#ifndef CPP04_EX03_Ice_H_
# define CPP04_EX03_Ice_H_

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(const Ice&);
	~Ice(void);
	Ice&	operator=(const Ice&);

	AMateria*			clone(void) const;
	void				use(ICharacter& target);
};

#endif
