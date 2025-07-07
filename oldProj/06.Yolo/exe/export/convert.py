# python3 C:\Users\john\Desktop\YOLOv8-TensorRT-CPP-main\scripts\pytorch2onnx.py --pt_path yolov8x.pt

from ultralytics import YOLO

# Load the YOLOv8 model
model = YOLO("yolov8l.pt")

# Export the model to TorchScript format
model.export(format="torchscript")