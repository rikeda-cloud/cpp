#ifndef CPP04_EX03_Cure_H_
# define CPP04_EX03_Cure_H_

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
	Cure(void);
	Cure(const Cure&);
	~Cure(void);
	Cure&	operator=(const Cure&);

	AMateria*			clone(void) const;
	void				use(ICharacter& target);
};

#endif
