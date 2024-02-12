#ifndef CPP04_EX03_AMateria_H_
# define CPP04_EX03_AMateria_H_

#include <string>

class ICharacter;

class AMateria {
private:
	AMateria(void);

protected:
	std::string	type_;

public:
	virtual	~AMateria(void);
	AMateria&	operator=(const AMateria&);

	AMateria(std::string const & type);

	std::string	const &	getType() const; //Returns the materia type
	
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif
