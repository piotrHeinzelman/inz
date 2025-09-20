from ultralytics import YOLO
import os
import time



# Load a COCO-pretrained YOLOv8n model
model = YOLO("yolov8l.pt")

# Display model information (optional)
model.info()

# Train the model on the COCO8 example dataset for 100 epochs
#results = model.train(data="coco8.yaml", epochs=10, imgsz=640)

# Run inference with the YOLOv8n model on the 'bus.jpg' image
# results = model("path/to/bus.jpg")

start=time.time()

results = model.predict("path/to/bus.jpg")

end=time.time()
d=end-start
print("# Prediction Time: " , d)


# https://github.com/ultralytics/ultralytics/tree/main

#@software{yolov8_ultralytics,
#  author = {Glenn Jocher and Ayush Chaurasia and Jing Qiu},
#  title = {Ultralytics YOLOv8},
#  version = {8.0.0},
#  year = {2023},
#  url = {https://github.com/ultralytics/ultralytics},
#  orcid = {0000-0001-5950-6979, 0000-0002-7603-6750, 0000-0003-3783-7069},
#  license = {AGPL-3.0}
#}