cmake_minimum_required(VERSION 3.2)

# Global properties
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Project name
project(embedded_python CXX)

# c++ flas
if(UNIX OR APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -O3 -Wall -std=c++17")
  #set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3 -march=native -std=c++11")
endif()

# Python Library
#find_package(PythonLibs)
find_package(Python COMPONENTS Interpreter Development)

message("Python_FOUND:${Python_FOUND}")
message("Python_VERSION:${Python_VERSION}")
message("Python_Development_FOUND:${Python_Development_FOUND}")
message("Python_LIBRARIES:${Python_LIBRARIES}")
message("Python_INCLUDE_DIRS:${Python_INCLUDE_DIRS}")

include_directories(${Python_INCLUDE_DIRS})
list(APPEND LINKLIBS ${Python_LIBRARIES})

include_directories("include")
#file(GLOB_RECURSE EP_HEADER_FILES  "include/*.h")
#file(GLOB_RECURSE EP_SOURCE_FILES  "source/*.cpp")

# Examples
file(GLOB EXAMPLE_HEADER_FILES "examples/*.h")
file(GLOB EXAMPLE_SOURCE_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/examples" "examples/*.cpp")
foreach(EXAMPLE_SOURCE_FILE ${EXAMPLE_SOURCE_FILES})
  string(REGEX REPLACE "(.*)\\.cpp" "\\1" EXAMPLE_NAME ${EXAMPLE_SOURCE_FILE})
  set(EXAMPLE_TARGET "embedding-python-${EXAMPLE_NAME}")
  add_executable(${EXAMPLE_TARGET} ${EXAMPLE_HEADER_FILES} "examples/${EXAMPLE_SOURCE_FILE}")
  set_target_properties(${EXAMPLE_TARGET} PROPERTIES COMPILE_FLAGS "${PEDANTIC_COMPILE_FLAGS}" FOLDER "examples")
  target_link_libraries(${EXAMPLE_TARGET} ${LINKLIBS})
endforeach()