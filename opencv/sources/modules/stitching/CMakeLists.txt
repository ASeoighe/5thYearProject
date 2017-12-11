set(the_description "Images stitching")
<<<<<<< HEAD
=======
ocv_warnings_disable(CMAKE_CXX_FLAGS -Woverloaded-virtual)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
if(ENABLE_DYNAMIC_CUDA)
  add_definitions(-DDYNAMIC_CUDA_SUPPORT)
  ocv_define_module(stitching opencv_imgproc opencv_features2d opencv_calib3d opencv_objdetect OPTIONAL opencv_nonfree)
else()
  ocv_define_module(stitching opencv_imgproc opencv_features2d opencv_calib3d opencv_objdetect OPTIONAL opencv_gpu opencv_nonfree)
endif()
