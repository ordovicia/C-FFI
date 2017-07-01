cmake_minimum_required(VERSION 3.0.0)

find_package(PythonInterp 3 REQUIRED)
find_package(PythonLibs 3 REQUIRED)

message("Python version:\n\tpython${PYTHON_VERSION_MAJOR}")
# if(APPLE AND ${PYTHON_VERSION_MAJOR} EQUAL 3)
    find_package(Boost COMPONENTS python3)
# else()
#     find_package(Boost COMPONENTS python)
# endif()

include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

file(GLOB PYTHON_SRCS *.py)
file(COPY ${PYTHON_SRCS} DESTINATION .)

python_add_module(fn fn.cpp)
python_add_module(cls cls.cpp)
