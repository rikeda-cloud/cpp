#ifndef CPP01_EX04_FileReplacer_H_
# define CPP01_EX04_FileReplacer_H_

#include <string>
#include <fstream>

class FileReplacer {
private:
	std::string		file_;
	std::string		from_;
	std::string		to_;
	std::ifstream	fs_;
	std::ofstream	fs_replace_;

	int				Open(void);
	int				Close(void);
	void			Save(std::string&);
	std::string		ReplaceLine(std::string line);

public:
	FileReplacer(std::string, std::string, std::string);
	FileReplacer(const FileReplacer&);
	~FileReplacer(void);
	FileReplacer&	operator=(const FileReplacer&);

	int	Replace(void);
};

#endif
