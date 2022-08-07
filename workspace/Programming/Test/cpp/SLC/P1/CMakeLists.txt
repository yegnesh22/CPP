project( P1 )
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( P1 P1.cpp )
target_link_libraries( P1 ${OpenCV_LIBS} )

