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

// int	main(void)
// {
// 	int		num_animals = 100;
// 	Animal*	animals[100];

// 	int	i = 0;
// 	for (; i < num_animals / 2; i++)
// 		animals[i] = new Dog();
// 	for (; i < num_animals; i++)
// 		animals[i] = new Cat();
// 	for (int i = 0; i < num_animals; i++)
// 		delete animals[i];
// 	return 0;
// }

// int	main(void) {
// 	Dog*	dogs[2];
// 	Cat*	cats[2];
// 	dogs[0] = new Dog();
// 	dogs[1] = new Dog();
// 	cats[0] = new Cat();
// 	cats[1] = new Cat();

// 	dogs[0]->makeSound();
// 	dogs[1]->makeSound();
// 	cats[0]->makeSound();
// 	cats[1]->makeSound();

// 	*dogs[0] = *dogs[1];
// 	*cats[0] = *cats[1];
// 	*dogs[1] = *dogs[0];
// 	*cats[1] = *cats[0];

// 	delete dogs[0];
// 	delete dogs[1];
// 	delete cats[0];
// 	delete cats[1];
// 	return 0;
// }

int	main(void) {
	Animal	*animal[2];
	animal[0] = new Dog();
	animal[1] = new Cat();
	Dog	dog(*dynamic_cast<Dog*>(animal[0]));
	Cat	cat(*dynamic_cast<Cat*>(animal[1]));

	delete animal[0];
	delete animal[1];
	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q brain");
// }
