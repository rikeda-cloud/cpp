#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include <iostream>

void	test_default(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	test_MateriaSource_not_learn_create(void) {
	IMateriaSource*	src = new MateriaSource();

	AMateria*	materia1 = src->createMateria("ice");
	if (materia1 == NULL)
		std::cout << "no materia" << std::endl;
	else {
		std::cout << materia1->getType();
		delete materia1;
	}
	delete src;
}

int	main(void) {
	test_default();
	test_MateriaSource_not_learn_create();

	return 0;
}

	__attribute__((destructor)) static void destructor()
{
   system("leaks -q materiacharacter");
}
