# cmake -LAH
# print cmake list variable
foreach(dir ${OpenCV_INCLUDE_DIRS})
  message(STATUS "include='${dir}'")
endforeach()
