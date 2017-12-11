if(NOT HAVE_OPENCL)
  ocv_module_disable(ocl)
  return()
endif()

set(the_description "OpenCL-accelerated Computer Vision")
ocv_define_module(ocl opencv_core opencv_imgproc opencv_features2d opencv_objdetect opencv_video opencv_calib3d opencv_ml "${OPENCL_LIBRARIES}")
if(TARGET opencv_test_ocl)
  target_link_libraries(opencv_test_ocl "${OPENCL_LIBRARIES}")
endif()
<<<<<<< HEAD
ocv_warnings_disable(CMAKE_CXX_FLAGS -Wshadow)
=======
ocv_warnings_disable(CMAKE_CXX_FLAGS -Wshadow -Woverloaded-virtual -Wunused-private-field)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
