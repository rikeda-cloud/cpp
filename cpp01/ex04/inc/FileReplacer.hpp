#ifndef CPP01_EX04_FileReplacer_H_
# define CPP01_EX04_FileReplacer_H_

#include <string>
#include <fstream>

class FileReplacer {
private:
	std::string		file_;
	std::string		s1_;
	std::string		s2_;
	std::ifstream	fs_;
	std::ofstream	fs_replace_;
	bool			_open(void);
	std::string		_replace_line(std::string line);
	void			_replace_s1_to_s2(void);

public:
	FileReplacer(std::string, std::string, std::string);
	~FileReplacer(void);
	void	replace(void);
};

#endif
