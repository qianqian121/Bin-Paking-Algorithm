cmake_minimum_required (VERSION 3.1)

project (bin_packing)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "-fpermissive")
# set(CMAKE_CXX_COMPILER /usr/bin/g++)
#set(CMAKE_BUILD_TYPE "Release")

find_package(OpenCV REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

SET(EIGEN_INCLUDE_DIR "/usr/include/eigen3")
include_directories(${EIGEN_INCLUDE_DIR} ${OpenCV_INCLUDE_DIRS})

include_directories(${OpenCV_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

include_directories(glm)

file(GLOB sources "MyPacking/*.cpp")

add_executable(bin_packing ${sources})
message("GLUT_LIBRARY" ${GLUT_LIBRARY})
target_link_libraries(bin_packing ${OpenCV_LIBS} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARIES} glut glfw dl X11 pthread Xrandr Xi Xxf86vm Xinerama Xcursor)
