#include "FileReplacer.hpp"
#include <fstream>
#include <iostream>

FileReplacer::FileReplacer(std::string filename, std::string s1, std::string s2) : file_(filename), s1_(s1), s2_(s2) {
}

FileReplacer::~FileReplacer(void) {
	if (fs_.is_open())
		fs_.close();
	if (fs_replace_.is_open())
		fs_replace_.close();
}

bool	FileReplacer::_open(void) {
	fs_.open(file_);
	if (!fs_.is_open())
		return false;
	fs_replace_.open(file_ + ".replace");
	if (!fs_replace_.is_open())
		return false;
	return true;
}

std::string	FileReplacer::_replace_line(std::string line) {
	size_t	idx = 0;

	if (s1_.length() == 0)
		return line;
	while ((idx = line.find_first_of(s1_, idx)) != std::string::npos) {
		line.erase(idx, s1_.length());
		line.insert(idx, s2_);
		idx += s2_.length();
	}
	return line;
}

void	FileReplacer::_replace_s1_to_s2(void) {
	while (true) {
		std::string line;
		fs_ >> line;
		if (!fs_)
			break ;
		line = _replace_line(line);
		fs_replace_ << line << std::endl;
	}
}

void	FileReplacer::replace(void) {
	if (file_.length() == 0)
		std::cerr << "filename is invalid" << std::endl;
	else if (_open() == false)
		std::cerr << "file open failed" << std::endl;
	else
		_replace_s1_to_s2();
}
