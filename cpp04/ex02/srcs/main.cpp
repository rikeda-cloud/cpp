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

	copy_dog.rememberIdea(3);
	copy_cat.rememberIdea(3);
}

void	test_assignment(void) {
	std::cout << "--- 代入演算子でアイデアがディープコピーになるかのテスト ---" << std::endl;
	Dog*	dog = new Dog();
	Cat*	cat = new Cat();
	dog->comeUpWithIdea(3, std::string("NEWDOGIDEA"));
	cat->comeUpWithIdea(3, std::string("NEWCATIDEA"));

	Dog	assignment_dog;
	Cat	assignment_cat;
	assignment_dog = *dog;
	assignment_cat = *cat;
	delete dog;
	delete cat;

	assignment_dog.rememberIdea(3);
	assignment_cat.rememberIdea(3);
}

void	test_brain(void) {
	std::cout << "--- Brainクラスのテスト ---" << std::endl;
	Brain	*brain = new Brain();

	brain->setIdea(-1, "idea1"); // idea[0~99]の範囲におさまらないインデックス
	brain->setIdea(100, "idea1"); // idea[0~99]の範囲におさまらないインデックス
	
	// std::stringのデフォルト値で初期化されている
	std::cout << "brain[0] = \"" << *brain->getIdea(0) << "\"" << std::endl;
	brain->setIdea(1, "idea1");
	std::cout << "brain[1] = \"" << *brain->getIdea(1) << "\"" << std::endl;
	Brain	copy_brain(*brain);
	Brain	assignment_brain;
	assignment_brain = *brain;
	delete brain; // ここでコピー＆代入元のbrainを削除
	std::cout << "copy[1] = \"" << *copy_brain.getIdea(1) << "\"" << std::endl;
	std::cout << "assignment[1] = \"" << *assignment_brain.getIdea(1) << "\"" << std::endl;
}

void	test_create_Animal_instance(void) {
	// Animal	animal;
	// Animal*	animal_ptr = new Animal;
	// delete animal_ptr;
}

int	main(void) {
	test_default();
	test_default2();
	test_copy();
	test_assignment();
	test_brain();
	test_create_Animal_instance();

	return 0;
}

	__attribute__((destructor)) static void destructor()
{
   system("leaks -q abc");
}
