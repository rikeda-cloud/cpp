#include "FileReplacer.hpp"
#include <fstream>
#include <iostream>

FileReplacer::FileReplacer(std::string file) : file_(file) {
	Open();
}

FileReplacer::FileReplacer(const FileReplacer& filereplacer) : file_(filereplacer.file_) {
	Open();
}

FileReplacer::~FileReplacer(void) {
	Close();
}

FileReplacer&	FileReplacer::operator=(const FileReplacer& filereplacer) {
	if (this != &filereplacer) {
		this->is_failed_ = false;
		this->Close();
		this->file_ = filereplacer.file_;
		if (this->is_failed_ == false)
			this->Open();
	}
	return *this;
}

void	FileReplacer::Open(void) {
	if (file_.size() == 0) {
		is_failed_ = true;
		return ;
	}
	fs_.open(file_.c_str());
	if (fs_.fail()) {
		is_failed_ = true;
		return ;
	}
	std::string	replace_file(file_);
	replace_file += ".replace";
	fs_replace_.open(replace_file.c_str());
	if (fs_replace_.fail()) {
		fs_.close();
		is_failed_ = true;
		return ;
	}
	is_failed_ = false;
}

void	FileReplacer::Close(void) {
	if (fs_.is_open()) {
		fs_.close();
		if (fs_.fail())
			is_failed_ = true;
	}
	if (fs_replace_.is_open()) {
		fs_replace_.close();
		if (fs_replace_.fail())
			is_failed_ = true;
	}
}

int	FileReplacer::SaveLine(std::string& line) {
	fs_replace_ << line << std::endl;
	if (fs_replace_.fail()) {
		is_failed_ = true;
		std::cerr << "output error" << std::endl;
		return -1;
	}
	return 0;
}

std::string	FileReplacer::ReplaceLine(std::string line, std::string& from, std::string& to) {
	size_t	idx = 0;

	if (from.length() == 0)
		return line;
	while ((idx = line.find(from, idx)) != std::string::npos) {
		line.erase(idx, from.length());
		line.insert(idx, to);
		idx += to.length();
	}
	return line;
}

int	FileReplacer::Replace(std::string from, std::string to) {
	if (is_failed_) {
		std::cerr << "file error" << std::endl;
		return -1;
	}
	while (true) {
		std::string line;
		std::getline(fs_, line);
		if (!fs_)
			break ;
		line = ReplaceLine(line, from, to);
		if (SaveLine(line) == -1)
			return -1;
	}
	return 0;
}
