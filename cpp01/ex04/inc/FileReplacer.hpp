#ifndef CPP01_EX04_FileReplacer_H_
# define CPP01_EX04_FileReplacer_H_

#include <string>
#include <fstream>

class FileReplacer {
private:
	std::string		file_;
	std::ifstream	fs_;
	std::ofstream	fs_replace_;
	bool			is_failed_;

	void			Open(void);
	void			Close(void);
	void			SaveLine(std::string&);
	std::string		ReplaceLine(std::string line, std::string& from, std::string& to);

	FileReplacer(void);

public:
	FileReplacer(std::string file);
	FileReplacer(const FileReplacer&);
	~FileReplacer(void);
	FileReplacer&	operator=(const FileReplacer&);

	int		Replace(std::string, std::string);
};

#endif
