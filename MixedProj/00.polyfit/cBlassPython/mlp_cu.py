import cudnn

print(cudnn.backend_version())



import torch

torch.manual_seed(42)
assert torch.cuda.is_available()
device = torch.device("cuda")

handle = cudnn.create_handle()

# Create tensor in NHWC format then permute to NCHW
X_gpu = torch.randn(8, 56, 56, 64, device=device, dtype=torch.float16).permute(
    0, 3, 1, 2
)
W_gpu = torch.randn(32, 3, 3, 64, device=device, dtype=torch.float16).permute(
    0, 3, 1, 2
)


with cudnn.Graph(
    inputs=["conv2d::image", "conv2d::weight"],
    outputs=["conv_out"],
) as graph:
    Y = graph.conv_fprop(
        image=X_gpu,  # referencing tensor layout and type
        weight=W_gpu,  # referencing tensor layout and type
        padding=[1, 1],
        stride=[1, 1],
        dilation=[1, 1],
        compute_data_type=cudnn.data_type.FLOAT,
        name="conv2d",
    )
    # either set io_data_type in Graph or set_data_type on the output tensor
    Y.set_output(True).set_data_type(cudnn.data_type.HALF).set_name("conv_out")




Y_gpu = graph(
    X_gpu, W_gpu, handle=handle
)  # reading the tensor value to execute the graph


Y_ref = torch.nn.functional.conv2d(X_gpu, W_gpu, padding=1)
torch.testing.assert_close(Y_gpu, Y_ref, atol=5e-3, rtol=3e-3)


print(Y_gpu)



