cmake_minimum_required(VERSION 3.8.0)

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

find_package(PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_SWIG_FLAGS "")

file(GLOB SWIG_FILES *.i)
file(GLOB SRC_FILES *.cpp)

set_source_files_properties(${SWIG_FILES} PROPERTIES CPLUSPLUS ON)
set_source_files_properties(${SWIG_FILES} PROPERTIES SWIG_FLAGS "-includeall")

swig_add_library(example
    LANGUAGE python
    SOURCES ${SWIG_FILES} ${SRC_FILES})
swig_link_libraries(example ${PYTHON_LIBRARIES})
