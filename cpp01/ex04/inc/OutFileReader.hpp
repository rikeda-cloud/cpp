#ifndef CPP01_EX04_OutFileReader_H_
# define CPP01_EX04_OutFileReader_H_

#include <string>
#include <fstream>

class OutFileReader {
public:
	OutFileReader(std::string);
	OutFileReader(const OutFileReader&);
	~OutFileReader(void);
	OutFileReader&	operator=(const OutFileReader&);

	void	Save(std::string& charsets);
	bool	IsFail(void);

private:
	std::string		fname_;
	std::ofstream	fs_;
	bool			is_fail_;

	int		Open(void);
	void	Close(void);
	OutFileReader(void);
};

#endif
