#ifndef RESOURCEe_FILES_MANAGER_H
#define RESOURCEe_FILES_MANAGER_H

#include <map>
#include <vector>
#include <memory>

namespace Resource_files{

	struct File_ptr{	

		File_ptr(char *_start, char *_end);
		File_ptr() = default;

		char *start;
		char *end;
	};

	class Resource_files_getter{
	private:
                std::map<std::string, File_ptr> file_pointers; 

		void set_file_pointers();

		Resource_files_getter();
		Resource_files_getter(const Resource_files_getter&) = delete;
		Resource_files_getter(Resource_files_getter &&) = delete;
		Resource_files_getter& operator =(Resource_files_getter &) = delete;
	public:

		static std::shared_ptr<Resource_files_getter> get_instance();

		std::vector<std::string> get_file_names();
		bool get_file_ptr(const std::string & file_name, File_ptr & file);
	};


}
#endif /* RESOURCEe_FILES_MANAGER_H */
