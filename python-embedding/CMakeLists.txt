cmake_minimum_required(VERSION 3.0.0)

find_package(PythonInterp)
find_package(PythonLibs)

message("Python version:\n\tpython${PYTHON_VERSION_MAJOR}")
if(APPLE AND ${PYTHON_VERSION_MAJOR} EQUAL 3)
    FIND_PACKAGE(Boost COMPONENTS python3)
else()
    FIND_PACKAGE(Boost COMPONENTS python)
endif()

include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
# link_libraries(${boost_LIBRARIES} ${PYTHON_LIBRARIES})

file(GLOB CPP_SOURCES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
file(GLOB PY_SOURCES ${CMAKE_CURRENT_LIST_DIR}/*.py)

add_executable(embedding ${CPP_SOURCES})
target_link_libraries(embedding ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
file(COPY ${PY_SOURCES} DESTINATION .)
