cmake_minimum_required(VERSION 3.0.0)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)

message("Python version:\n\tpython${PYTHON_VERSION_MAJOR}")
if(APPLE AND ${PYTHON_VERSION_MAJOR} EQUAL 3)
    FIND_PACKAGE(Boost COMPONENTS python3)
else()
    FIND_PACKAGE(Boost COMPONENTS python)
endif()

include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
# link_libraries(${boost_LIBRARIES} ${PYTHON_LIBRARIES})

add_executable(call_python call_python.cpp)
target_link_libraries(call_python ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

file(COPY call_python.py DESTINATION .)
