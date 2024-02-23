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

	void	save(std::string&);
	bool	isFail(void) const;

private:
	std::string		fname_;
	std::ofstream	fs_;
	bool			is_fail_;

	void	open(void);
	void	close(void);
	OutFileReader(void);
};

#endif
