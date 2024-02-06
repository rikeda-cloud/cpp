#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

// int	main(void)
// {
// 	Weapon	weapon("*******");
// 	HumanA	a("A", weapon);
// 	HumanB	b("B");
// 
// 	std::cout << "--- HumanA attack ---" << std::endl;
// 	a.attack();
// 	std::cout << std::endl;
// 
// 	std::cout << "--- HumanB(not set weapon) attack ---" << std::endl;
// 	b.attack();
// 	std::cout << std::endl;
// 
// 	std::cout << "--- HumanB set ******* ---" << std::endl;
// 	b.setWeapon(weapon);
// 	std::cout << std::endl;
// 
// 	std::cout << "--- HumanB(have *******) attack ---" << std::endl;
// 	b.attack();
// 
// 	return 0;
// }

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q UnnecessaryViolence");
// }
