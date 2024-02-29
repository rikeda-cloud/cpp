#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void	test_default(void) {
	std::cout << "--- 課題PDFにあるサンプルmainと同じテスト ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void	test_wrong(void) {
	std::cout << "--- 課題PDFにあるサンプルmainをWrongで書き換えたテスト ---" << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	delete meta;
	delete i;
}

void	test_child_ptr(void) {
	std::cout << "--- 親クラスのポインタではなく子クラスのポインタを使用 ---" << std::endl;
	const Dog*		dog = new Dog();
	const Cat*		cat = new Cat();
	const WrongCat*	wrong_cat = new WrongCat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	wrong_cat->makeSound();

	delete dog;
	delete cat;
	delete wrong_cat;
}

void	test_copy_and_assignment(void) {
	std::cout << "--- コピーコンストラクタと代入演算子のテスト ---" << std::endl;
	const Cat*		cat = new Cat();
	const WrongCat*	wrong_cat = new WrongCat();
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	cat->makeSound();
	wrong_cat->makeSound();
	Cat			another_cat(*cat); // copy constructor
	WrongCat	another_wrong_cat(*wrong_cat); // copy constructor
	delete cat;
	delete wrong_cat;
	std::cout << another_cat.getType() << " " << std::endl;
	std::cout << another_wrong_cat.getType() << " " << std::endl;
	another_cat.makeSound();
	another_wrong_cat.makeSound();
	another_cat = Cat(); // assignment operator
	another_wrong_cat = WrongCat(); // assignment operator
	std::cout << another_cat.getType() << " " << std::endl;
	std::cout << another_wrong_cat.getType() << " " << std::endl;
	another_cat.makeSound();
	another_wrong_cat.makeSound();
}

int main()
{
	test_default();
	test_wrong();
	test_child_ptr();
	test_copy_and_assignment();

	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q Animal");
// }
