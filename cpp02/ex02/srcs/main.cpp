#include "Fixed.hpp"
#include <iostream>

// int main( void ) {
// 	Fixed		a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	return 0;
// }

int	main(void) {
	Fixed	a(1000);
	Fixed	b(1000);

	std::cout << (a * b).toFloat() << std::endl;

	return 0;
}
