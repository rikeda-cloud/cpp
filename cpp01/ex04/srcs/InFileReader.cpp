#include "InFileReader.hpp"

InFileReader::InFileReader(std::string file) : fname_(file), is_fail_(false) {
	open();
}

InFileReader::InFileReader(const InFileReader& reader) : fname_(reader.fname_), is_fail_(false) {
	open();
}

InFileReader::~InFileReader(void) {
	close();
}

InFileReader&	InFileReader::operator=(const InFileReader& reader) {
	if (this != &reader) {
		this->fname_ = reader.fname_;
		close();
		open();
	}
	return *this;
}

void	InFileReader::open() {
	if (fname_.size() == 0) {
		is_fail_ = true;
		return ;
	}
	fs_.open(fname_.c_str());
	if (fs_.fail())
		is_fail_ = true;
}

void	InFileReader::close(void) {
	if (fs_.is_open())
		fs_.close();
}

std::string	InFileReader::getAllChars(void) {
	std::string	all_chars;
	std::string	line;

	while (std::getline(fs_, line)) {
		all_chars += line;
		all_chars += std::string("\n");
	}
	if (fs_.eof())
		is_fail_ = false;
	else if (fs_.fail())
		is_fail_ = true;
	return all_chars;
}

bool	InFileReader::isFail(void) const {
	return is_fail_;
}
