# All examples
file(GLOB SRCS tests/example-*.cpp)
foreach(src ${SRCS})
    string(REGEX REPLACE "(^.*/|.cpp$)" "" exe ${src})
    add_executable(${exe} ${src})
    target_link_libraries(${exe} ${PROJECT_NAME} utils g2o ${PROJECT_NAME})
endforeach(src)
