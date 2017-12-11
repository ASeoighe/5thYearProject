set(the_description "The ts module")

if(IOS)
  ocv_module_disable(ts)
endif()

set(OPENCV_MODULE_TYPE STATIC)
set(OPENCV_MODULE_IS_PART_OF_WORLD FALSE)

ocv_warnings_disable(CMAKE_CXX_FLAGS -Wundef)

<<<<<<< HEAD
ocv_add_module(ts opencv_core opencv_features2d)
=======
ocv_add_module(ts opencv_core opencv_features2d opencv_highgui opencv_imgproc opencv_video opencv_calib3d)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

ocv_glob_module_sources()
ocv_module_include_directories()
ocv_create_module()

ocv_add_precompiled_headers(${the_module})
