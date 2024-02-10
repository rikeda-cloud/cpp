#include "Point.hpp"
#include <iostream>

int main( void ) {
	Point	a(-10, 10);
	Point	b(10, 10);
	Point	c(0, -10);
	std::cout << bsp(a, b, c, Point(0, 0)) << std::endl; // 三角形の中心
	std::cout << bsp(a, b, c, Point(-10, 10)) << std::endl; // 座標aと同じ座標
	std::cout << bsp(a, b, c, Point(10, 10)) << std::endl; // 座標bと同じ座標
	std::cout << bsp(a, b, c, Point(0, -10)) << std::endl; //座標cと同じ座標
	std::cout << bsp(a, b, c, Point(0, 10)) << std::endl; // 座標aと座標bを繋ぐ線上
	std::cout << bsp(a, b, c, Point(0, 9.9)) << std::endl; // 座標aと座標bを繋ぐ線の少し内側
	std::cout << bsp(a, b, c, Point(0, 9.99)) << std::endl; // 座標aと座標bを繋ぐ線のギリギリ内側
	std::cout << bsp(a, b, c, Point(0, 9.999)) << std::endl; // 座標aと座標bを繋ぐ線の少し内側だが、浮動小数点を固定小数点に直すときに情報落ちする
	return 0;
}
