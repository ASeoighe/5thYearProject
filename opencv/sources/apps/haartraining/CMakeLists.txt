SET(OPENCV_HAARTRAINING_DEPS opencv_core opencv_imgproc opencv_highgui opencv_objdetect opencv_calib3d opencv_video opencv_features2d opencv_flann opencv_legacy)
ocv_check_dependencies(${OPENCV_HAARTRAINING_DEPS})

if(NOT OCV_DEPENDENCIES_FOUND)
  return()
endif()

project(haartraining)

ocv_include_directories("${CMAKE_CURRENT_SOURCE_DIR}" "${OpenCV_SOURCE_DIR}/include/opencv")
ocv_include_modules(${OPENCV_HAARTRAINING_DEPS})

<<<<<<< HEAD
=======
ocv_warnings_disable(CMAKE_CXX_FLAGS -Wunused-private-field)

>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
if(WIN32)
  link_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

<<<<<<< HEAD
link_libraries(${OPENCV_HAARTRAINING_DEPS} opencv_haartraining_engine)

=======
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
# -----------------------------------------------------------
#  Library
# -----------------------------------------------------------
set(cvhaartraining_lib_src
  _cvcommon.h
  cvclassifier.h
  _cvhaartraining.h
  cvhaartraining.h
  cvboost.cpp
  cvcommon.cpp
  cvhaarclassifier.cpp
  cvhaartraining.cpp
  cvsamples.cpp
<<<<<<< HEAD
  )

add_library(opencv_haartraining_engine STATIC ${cvhaartraining_lib_src})
=======
  cvsamplesoutput.cpp
  cvsamplesoutput.h
  ioutput.h
  )

add_library(opencv_haartraining_engine STATIC ${cvhaartraining_lib_src})
target_link_libraries(opencv_haartraining_engine ${OPENCV_HAARTRAINING_DEPS})
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
set_target_properties(opencv_haartraining_engine PROPERTIES
                      DEBUG_POSTFIX "${OPENCV_DEBUG_POSTFIX}"
                      ARCHIVE_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH}
                      RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
<<<<<<< HEAD
                      INSTALL_NAME_DIR lib
=======
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
                     )

# -----------------------------------------------------------
#  haartraining
# -----------------------------------------------------------

add_executable(opencv_haartraining cvhaartraining.h haartraining.cpp)
<<<<<<< HEAD
=======
target_link_libraries(opencv_haartraining ${OPENCV_HAARTRAINING_DEPS} opencv_haartraining_engine)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
set_target_properties(opencv_haartraining PROPERTIES
                      DEBUG_POSTFIX "${OPENCV_DEBUG_POSTFIX}"
                      OUTPUT_NAME "opencv_haartraining")

# -----------------------------------------------------------
#  createsamples
# -----------------------------------------------------------

add_executable(opencv_createsamples cvhaartraining.h createsamples.cpp)
<<<<<<< HEAD
=======
target_link_libraries(opencv_createsamples ${OPENCV_HAARTRAINING_DEPS} opencv_haartraining_engine)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
set_target_properties(opencv_createsamples PROPERTIES
                      DEBUG_POSTFIX "${OPENCV_DEBUG_POSTFIX}"
                      OUTPUT_NAME "opencv_createsamples")

# -----------------------------------------------------------
#  performance
# -----------------------------------------------------------
add_executable(opencv_performance performance.cpp)
<<<<<<< HEAD
=======
target_link_libraries(opencv_performance ${OPENCV_HAARTRAINING_DEPS} opencv_haartraining_engine)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
set_target_properties(opencv_performance PROPERTIES
                      DEBUG_POSTFIX "${OPENCV_DEBUG_POSTFIX}"
                      OUTPUT_NAME "opencv_performance")

# -----------------------------------------------------------
#  Install part
# -----------------------------------------------------------

if(INSTALL_CREATE_DISTRIB)
  if(BUILD_SHARED_LIBS)
    install(TARGETS opencv_haartraining RUNTIME DESTINATION ${OPENCV_BIN_INSTALL_PATH} CONFIGURATIONS Release COMPONENT dev)
    install(TARGETS opencv_createsamples RUNTIME DESTINATION ${OPENCV_BIN_INSTALL_PATH} CONFIGURATIONS Release COMPONENT dev)
    install(TARGETS opencv_performance RUNTIME DESTINATION ${OPENCV_BIN_INSTALL_PATH} CONFIGURATIONS Release COMPONENT dev)
  endif()
else()
  install(TARGETS opencv_haartraining RUNTIME DESTINATION ${OPENCV_BIN_INSTALL_PATH} COMPONENT dev)
  install(TARGETS opencv_createsamples RUNTIME DESTINATION ${OPENCV_BIN_INSTALL_PATH} COMPONENT dev)
  install(TARGETS opencv_performance RUNTIME DESTINATION ${OPENCV_BIN_INSTALL_PATH} COMPONENT dev)
endif()

if(ENABLE_SOLUTION_FOLDERS)
  set_target_properties(opencv_performance PROPERTIES FOLDER "applications")
  set_target_properties(opencv_createsamples PROPERTIES FOLDER "applications")
  set_target_properties(opencv_haartraining PROPERTIES FOLDER "applications")
  set_target_properties(opencv_haartraining_engine PROPERTIES FOLDER "applications")
endif()
