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
