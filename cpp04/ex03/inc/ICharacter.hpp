#ifndef CPP04_EX03_ICharacter_H_
# define CPP04_EX03_ICharacter_H_

#include <string>

class AMateria;

class ICharacter {
public:
	virtual ~ICharacter();
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif
