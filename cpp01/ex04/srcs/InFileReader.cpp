#include "InFileReader.hpp"

InFileReader::InFileReader(std::string file)
	:	fname_(file),
		is_fail_(false) {
	if (Open() == -1)
		is_fail_ = true;
}

InFileReader::InFileReader(const InFileReader& reader)
	:	fname_(reader.fname_),
		is_fail_(false) {
	if (Open() == -1)
		is_fail_ = true;
}

InFileReader::~InFileReader(void) {
	Close();
}

InFileReader&	InFileReader::operator=(const InFileReader& reader) {
	if (this != &reader) {
		this->fname_ = reader.fname_;
		this->is_fail_ = false;
		Close();
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
	std::string	all_charsets;
	std::string	line;

	getline(fs_, line);
	while (true) {
		if (!fs_)
			break ;
		all_charsets += line;
		all_charsets += std::string("\n");
		getline(fs_, line);
	}
	return all_charsets;
}

bool	InFileReader::IsFail(void) {
	return is_fail_;
}
