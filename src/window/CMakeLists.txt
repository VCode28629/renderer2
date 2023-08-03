add_library(window STATIC window.cpp)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(OpenCV_LIBS 
        opencv_calib3d4d 
        opencv_core4d
        opencv_dnn4d
        opencv_features2d4d
        opencv_flann4d
        opencv_highgui4d
        opencv_imgcodecs4d
        opencv_imgproc4d
        opencv_ml4d
        opencv_objdetect4d
        opencv_photo4d
        opencv_videoio4d)
else()
    set(OpenCV_LIBS 
        opencv_calib3d4 
        opencv_core4 
        opencv_dnn4 
        opencv_features2d4 
        opencv_flann4 
        opencv_highgui4
        opencv_imgcodecs4
        opencv_imgproc4
        opencv_ml4
        opencv_objdetect4
        opencv_photo4
        opencv_videoio4)
endif()

target_link_libraries(window PRIVATE ${OpenCV_LIBS})
