#include "OutFileReader.hpp"

OutFileReader::OutFileReader(std::string file)
	:	fname_(file),
		is_fail_(false) {
	if (Open() == -1)
		is_fail_ = true;
}

OutFileReader::OutFileReader(const OutFileReader& reader)
	:	fname_(reader.fname_),
		is_fail_(false) {
	if (Open() == -1)
		is_fail_ = true;
}

OutFileReader::~OutFileReader(void) {
	Close();
}

OutFileReader&	OutFileReader::operator=(const OutFileReader& reader) {
	if (this != &reader) {
		this->fname_ = reader.fname_;
		this->is_fail_ = false;
		Close();
		if (Open() == -1)
			is_fail_ = true;
	}
	return *this;
}

int	OutFileReader::Open(void) {
	if (fname_.size() == 0)
		return -1;
	fs_.open(fname_.c_str());
	if (fs_.fail())
		return -1;
	return 0;
}

void	OutFileReader::Close(void) {
	if (fs_.is_open())
		fs_.close();
}

void	OutFileReader::Save(std::string& charsets) {
	fs_ << charsets;
	if (fs_.fail())
		is_fail_ = true;
}

bool	OutFileReader::IsFail(void) {
	return is_fail_;
}
