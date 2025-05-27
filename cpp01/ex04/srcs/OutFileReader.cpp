#include "OutFileReader.hpp"

OutFileReader::OutFileReader(std::string file) : fname_(file), is_fail_(false) {
	open();
}

OutFileReader::OutFileReader(const OutFileReader& reader) : fname_(reader.fname_), is_fail_(false) {
	open();
}

OutFileReader::~OutFileReader(void) {
	close();
}

OutFileReader&	OutFileReader::operator=(const OutFileReader& reader) {
	if (this != &reader) {
		this->fname_ = reader.fname_;
		this->is_fail_ = false;
		close();
		open();
	}
	return *this;
}

void	OutFileReader::open(void) {
	if (fname_.size() == 0) {
		is_fail_ = true;
		return ;
	}
	fs_.open(fname_.c_str());
	if (fs_.fail())
		is_fail_ = true;
}

void	OutFileReader::close(void) {
	if (fs_.is_open())
		fs_.close();
}

void	OutFileReader::save(std::string& chars) {
	fs_ << chars;
	if (fs_.fail())
		is_fail_ = true;
}

bool	OutFileReader::isFail(void) const {
	return is_fail_;
}
