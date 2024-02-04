#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;

// 	return 0;
// }

int	main(void)
{
	int		num_animals = 100;
	Animal*	animals[100];

	int	i = 0;
	for (; i < num_animals / 2; i++)
		animals[i] = new Dog();
	for (; i < num_animals; i++)
		animals[i] = new Cat();
	for (int i = 0; i < num_animals; i++)
		delete animals[i];
	return 0;
}

	__attribute__((destructor)) static void destructor()
{
   system("leaks -q abc");
}
