# Resource-files-Extention
A way how to add emded resources to the C++ executable project with the help of CMake and short Api

# How to use:
1. Add Resource files Extention inside your project
2. Create directory for resource files and lay them inside this directory
3. Add following calls to your CMake file:
```CMake
cmake_minimum_required(VERSION 3.1)
project(Embed_files_example)

#==================================================================
# Include directory with resource_files_manager.h 
#==================================================================
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../Resource\ files\ Extention/include)  

#==================================================================
# Set directory with resources
#==================================================================
set(RESOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Resources)

#==================================================================
# Add reference to CMakeLists.txt of libresources.a project 
#==================================================================
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Resource\ files\ Extention)

#==================================================================
# Build your project 
#==================================================================
add_executable(${PROJECT_NAME} main.cpp )

#==================================================================
# Link your project with libresources.a project 
#==================================================================
target_link_libraries(${PROJECT_NAME} 
        lib::resources
)
```
4. In your C++ project add following include:

```C++
#include "resource_files_manager.h"
using namespace Resource_files;
```
Now you get access to your embed files with the healp of short API highlites in resource_files_manager.h file.
A short working example inside Example directory:
```C++
#include <iostream>

#include "resource_files_manager.h"

using namespace Resource_files;

int main()
{
    std::shared_ptr<Resource_files_getter> resource_manager = 
            Resource_files_getter::get_instance();
    
    std::vector<std::string> file_names = resource_manager->get_file_names();
    
    File_ptr file_data_ptr;

    for(auto elem : file_names){
    	if(!resource_manager->get_file_ptr(elem, file_data_ptr))
	    std::cout << "Can`t find file: " << elem << std::endl;

	std::cout << "File " << elem << std::endl;
	std::cout << "_______________________________________\n";
	while(file_data_ptr.start != file_data_ptr.end){ std::cout << *file_data_ptr.start++;}
	std::cout << "=======================================\n";
    }
}
```

# How doesit works?
CMake do following job:

1. All files from your resources directory transferring into object files lik in this article: 
Visit http://www.linuxjournal.com/content/embedding-file-executable-aka-hello-world-version-5967

2. Generats source file for the resource_files_manager.h header file where add links to the embed files.
3. Adds all embed files into std::map with the key equals to the file name.
