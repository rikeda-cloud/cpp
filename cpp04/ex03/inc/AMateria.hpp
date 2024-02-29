#ifndef CPP04_EX03_AMateria_H_
# define CPP04_EX03_AMateria_H_

#include <string>

class ICharacter;

class AMateria {
public:
	AMateria(std::string const & type);
	AMateria(const AMateria&);
	virtual	~AMateria(void);
	AMateria&	operator=(const AMateria&);

	std::string	const &	getType() const; //Returns the materia type
	
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

protected:
	const std::string	type_;

private:
	AMateria(void);
};

#endif
