
rem call c:\Users\john\tf\Scripts\activate
rem cd X:\inz\MixedProj\01.MPL
python Python.Tensorflow\main_tensor.py >> log\tensor.log
pause
 


echo python -m venv c:\Users\john\tf
echo c:\Users\john\tf\Scripts\activate

REM # Anything above 2.10 is not supported on the GPU on Windows Native
echo python -m pip install "tensorflow<2.11"
REM 
echo python -c "import tensorflow as tf; print(tf.config.list_physical_devices('GPU'))"