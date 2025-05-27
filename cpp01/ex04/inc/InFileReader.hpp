#ifndef CPP01_EX04_InFileReader_H_
# define CPP01_EX04_InFileReader_H_

#include <string>
#include <fstream>

class InFileReader {
public:
	InFileReader(std::string file_name);
	InFileReader(const InFileReader&);
	~InFileReader(void);
	InFileReader&	operator=(const InFileReader&);

	std::string	getAllChars(void);
	bool		isFail(void) const;

private:
	std::string		fname_;
	std::ifstream	fs_;
	bool			is_fail_;

	void	open(void);
	void	close(void);
	InFileReader(void);
};

#endif
