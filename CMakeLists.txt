cmake_minimum_required(VERSION 3.3)
project(Backpropagation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)
set(SOURCE_FILES main.cpp Neuron.cpp Neuron.h Layers.cpp Layers.h)
add_executable(Backpropagation ${SOURCE_FILES})
target_link_libraries(Backpropagation ${OpenCV_LIBS})