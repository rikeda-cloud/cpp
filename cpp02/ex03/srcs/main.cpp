#include "Point.hpp"
#include <iostream>

static void	test_bsp(const Point& a, const Point& b, const Point& c, const Point& p) {
	const bool	result = bsp(a, b, c, p);
	std::cout << "["
		<< "a = (" << a.getX() << ", " << a.getY() << ") "
		<< "b = (" << b.getX() << ", " << b.getY() << ") "
		<< "c = (" << c.getX() << ", " << c.getY() << ") "
		<< "p = (" << p.getX() << ", " << p.getY() << ")"
		<< "] = " << (result ? "True" : "False") << std::endl; // 三角形の中心
}

int main( void ) {
	Point	a(-10, 10);
	Point	b(10, 10);
	Point	c(0, -10);

	test_bsp(a, b, c, Point(0, 0)); // 三角形の中心
	test_bsp(a, b, c, Point(-10, 10)); // 座標aと同じ座標
	test_bsp(a, b, c, Point(10, 10)); // 座標bと同じ座標
	test_bsp(a, b, c, Point(0, -10)); //座標cと同じ座標
	test_bsp(a, b, c, Point(0, 10)); // 座標aと座標bを繋ぐ線上
	test_bsp(a, b, c, Point(0, 9.9)); // 座標aと座標bを繋ぐ線の少し内側
	test_bsp(a, b, c, Point(0, 9.99)); // 座標aと座標bを繋ぐ線のギリギリ内側
	test_bsp(a, b, c, Point(0, 9.999)); // 座標aと座標bを繋ぐ線の少し内側だが、浮動小数点を固定小数点に直すときに情報落ちする
	return 0;
}
