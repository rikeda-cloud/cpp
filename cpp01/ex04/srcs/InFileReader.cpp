#include "InFileReader.hpp"

InFileReader::InFileReader(std::string file) : fname_(file), is_fail_(false) {
	if (Open() == -1)
		is_fail_ = true;
}

InFileReader::InFileReader(const InFileReader& reader) : fname_(reader.fname_), is_fail_(false) {
	if (Open() == -1)
		is_fail_ = true;
}

InFileReader::~InFileReader(void) {
	Close();
}

InFileReader&	InFileReader::operator=(const InFileReader& reader) {
	if (this != &reader) {
		this->fname_ = reader.fname_;
		Close();
		this->is_fail_ = false;
		if (Open() == -1)
			is_fail_ = true;
	}
	return *this;
}

int	InFileReader::Open() {
	if (fname_.size() == 0)
		return -1;
	fs_.open(fname_.c_str());
	if (fs_.fail())
		return -1;
	return 0;
}

void	InFileReader::Close(void) {
	if (fs_.is_open())
		fs_.close();
}

std::string	InFileReader::GetAllChars(void) {
	std::string	all_chars;
	std::string	line;

	while (std::getline(fs_, line)) {
		all_chars += line;
		all_chars += std::string("\n");
	}
	if (fs_.fail())
		is_fail_ = true;
	return all_chars;
}

bool	InFileReader::IsFail(void) {
	return is_fail_;
}
