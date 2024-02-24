#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// static void	print_fmt_fixed(const Fixed& f1, const Fixed& f2, std::string cmp, float result) {
// 	std::cout << f1 << cmp << f2 << " = " << result << std::endl;
// }

// static void	test_comparison(float float1, float float2) {
// 	Fixed	fixed1(float1);
// 	Fixed	fixed2(float2);

// 	std::cout << "[" << float1 << " CMP " << float2 << "]" << std::endl;
// 	print_fmt_fixed(fixed1, fixed2, " >  ", fixed1 > fixed2);
// 	print_fmt_fixed(fixed1, fixed2, " <  ", fixed1 < fixed2);
// 	print_fmt_fixed(fixed1, fixed2, " >= ", fixed1 >= fixed2);
// 	print_fmt_fixed(fixed1, fixed2, " <= ", fixed1 <= fixed2);
// 	print_fmt_fixed(fixed1, fixed2, " == ", fixed1 == fixed2);
// 	print_fmt_fixed(fixed1, fixed2, " != ", fixed1 != fixed2);
// }

// static void	test_arithmetic(float float1, float float2) {
// 	Fixed	fixed1(float1);
// 	Fixed	fixed2(float2);

// 	std::cout << "[" << float1 << " +-*/ " << float2 << "]" << std::endl;
// 	print_fmt_fixed(fixed1, fixed2, " + ", (fixed1 + fixed2).toFloat());
// 	print_fmt_fixed(fixed1, fixed2, " - ", (fixed1 - fixed2).toFloat());
// 	print_fmt_fixed(fixed1, fixed2, " * ", (fixed1 * fixed2).toFloat());
// 	print_fmt_fixed(fixed1, fixed2, " / ", (fixed1 / fixed2).toFloat());
// }

// static void	test_incremant_decremant(float float1) {
// 	Fixed	fixed1(float1);
// 	std::cout << "[base = " << fixed1 << "; ++() ()++ --() ()--" << "]" << std::endl;
// 	std::cout << "++ " << ++fixed1 << std::endl;
// 	Fixed	fixed2(float1);
// 	std::cout << fixed2++ << " ++" << std::endl;
// 	Fixed	fixed3(float1);
// 	std::cout << "-- " << --fixed3 << std::endl;
// 	Fixed	fixed4(float1);
// 	std::cout << fixed4-- << " --" << std::endl;
// }

// static void	test_min_max(float float1, float float2) {
// 	Fixed	fixed1(float1);
// 	Fixed	fixed2(float2);
// 	const Fixed	const_fixed1(float1);
// 	const Fixed	const_fixed2(float2);

// 	std::cout << "[" << float1 << " min or max " << float2 << "]" << std::endl;
// 	print_fmt_fixed(fixed1, fixed2, " min ", Fixed::min(fixed1, fixed2).toFloat());
// 	print_fmt_fixed(fixed1, fixed2, " max ", Fixed::max(fixed1, fixed2).toFloat());
// 	print_fmt_fixed(const_fixed1, const_fixed2, " const min ", const_cast<Fixed&>(Fixed::min(const_fixed1, const_fixed2)).toFloat());
// 	print_fmt_fixed(const_fixed1, const_fixed2, " const max ", const_cast<Fixed&>(Fixed::max(const_fixed1, const_fixed2)).toFloat());
// }

// int	main(void) {

// 	test_comparison(1.1, 1.2);
// 	test_arithmetic(1.1, 1.2);
// 	test_incremant_decremant(1.1);
// 	test_min_max(1.1, 1.2);

// 	return 0;
// }
