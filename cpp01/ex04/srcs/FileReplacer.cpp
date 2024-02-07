#include "FileReplacer.hpp"
#include <fstream>
#include <iostream>

FileReplacer::FileReplacer(std::string filename, std::string s1, std::string s2)
	:	file_(filename),
		from_(s1),
		to_(s2) {}

FileReplacer::FileReplacer(const FileReplacer& filereplacer)
	:	file_(filereplacer.file_),
		from_(filereplacer.from_),
		to_(filereplacer.to_) {}

FileReplacer::~FileReplacer(void) {
	Close();
}

FileReplacer&	FileReplacer::operator=(const FileReplacer& filereplacer) {
	if (this != &filereplacer) {
		this->file_ = filereplacer.file_;
		this->from_ = filereplacer.from_;
		this->to_ = filereplacer.to_;
	}
	return *this;
}

int	FileReplacer::Open(void) {
	fs_.open(file_.c_str());
	if (!fs_.is_open())
		return -1;
	std::string	replace_file(file_);
	replace_file += ".replace";
	fs_replace_.open(replace_file.c_str());
	if (!fs_replace_.is_open())
		return -1;
	return 0;
}

int	FileReplacer::Close(void) {
	if (fs_.is_open())
		fs_.close();
	if (fs_replace_.is_open())
		fs_replace_.close();
	return 0;
}

void	FileReplacer::Save(std::string& line) {
	fs_replace_ << line << std::endl;
}

std::string	FileReplacer::ReplaceLine(std::string line) {
	size_t	idx = 0;

	if (from_.length() == 0)
		return line;
	while ((idx = line.find(from_, idx)) != std::string::npos) {
		line.erase(idx, from_.length());
		line.insert(idx, to_);
		idx += to_.length();
	}
	return line;
}

int	FileReplacer::Replace(void) {
	if (file_.length() == 0) {
		std::cerr << "filename is invalid" << std::endl;
		return -1;
	}
	else if (Open() == -1) {
		std::cerr << "file open failed" << std::endl;
		return -1;
	}
	while (true) {
		std::string line;
		std::getline(fs_, line);
		if (!fs_)
			break ;
		line = ReplaceLine(line);
		Save(line);
	}
	Close();
	return 0;
}
