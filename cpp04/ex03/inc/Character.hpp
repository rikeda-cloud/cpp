#ifndef CPP04_EX03_Character_H_
# define CPP04_EX03_Character_H_

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
public:
	Character(std::string);
	Character(const Character&);
	~Character(void);
	Character&	operator=(const Character&);

	std::string const&	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

private:
	static const int	SLOT_CAPACITY = 4;
	std::string			name_;
	AMateria*			slot_[SLOT_CAPACITY];

	Character(void);
};

#endif
