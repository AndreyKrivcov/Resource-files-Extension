cmake_minimum_required(VERSION 3.1)
project(Embed_files_example)

#==================================================================
# Include directory with resource_files_manager.h 
#==================================================================
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../Resource\ files\ Extension/include)  

#==================================================================
# Set directory with resources
#==================================================================
set(RESOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Resources)

#==================================================================
# Add reference to CMakeLists.txt of libresources.a project 
#==================================================================
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../Resource\ files\ Extension ${CMAKE_CURRENT_BINARY_DIR}/Resource\ files\ Extension)

add_executable(${PROJECT_NAME} main.cpp )

#==================================================================
# Link your project with libresources.a project 
#==================================================================
target_link_libraries(${PROJECT_NAME} 
        lib::resources
)

