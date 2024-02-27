#ifndef CPP04_EX03_MateriaSource_H_
# define CPP04_EX03_MateriaSource_H_

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource&);
	~MateriaSource(void);
	MateriaSource&	operator=(const MateriaSource&);

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const& type);

private:
	static const int	SLOT_CAPACITY = 4;
	AMateria			*slot_[SLOT_CAPACITY];
};

#endif
