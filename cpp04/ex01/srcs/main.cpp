#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void	test_default(void)
{
	std::cout << "--- 課題PDFにあるサンプルmainと同じテスト ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}

void	test_default2(void)
{
	std::cout << "--- 課題PDFの文章で想定されているテスト ---" << std::endl;
	const int	num_animals = 10;
	Animal*		animals[10];

	int	i = 0;
	for (; i < num_animals / 2; ++i)
		animals[i] = new Dog();
	for (; i < num_animals; i++)
		animals[i] = new Cat();
	for (int i = 0; i < num_animals; ++i)
		animals[i]->makeSound();
	for (int i = 0; i < num_animals; ++i)
		delete animals[i];
}

void	test_copy(void) {
	std::cout << "--- コピーコンストラクタでアイデアがディープコピーになるかのテスト ---" << std::endl;
	Dog*	dog = new Dog();
	Cat*	cat = new Cat();
	dog->comeUpWithIdea(3, std::string("NEWDOGIDEA"));
	cat->comeUpWithIdea(3, std::string("NEWCATIDEA"));

	Dog	copy_dog(*dog);
	Cat	copy_cat(*cat);
	delete dog;
	delete cat;

	dog->rememberIdea(3);
	cat->rememberIdea(3);
}

void	test_assignment(void) {
	std::cout << "--- 代入演算子でアイデアがディープコピーになるかのテスト ---" << std::endl;
	Dog*	dog = new Dog();
	Cat*	cat = new Cat();
	dog->comeUpWithIdea(3, std::string("NEWDOGIDEA"));
	cat->comeUpWithIdea(3, std::string("NEWCATIDEA"));

	Dog	another_dog;
	Cat	another_cat;
	another_dog = *dog;
	another_cat = *cat;
	delete dog;
	delete cat;

	another_dog.rememberIdea(3);
	another_cat.rememberIdea(3);
}

int	main(void) {
	test_default();
	test_default2();
	test_copy();
	test_assignment();

	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q brain");
// }
