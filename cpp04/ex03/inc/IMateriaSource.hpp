#ifndef CPP04_EX03_IMateriaSource_H_
# define CPP04_EX03_IMateriaSource_H_

#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
