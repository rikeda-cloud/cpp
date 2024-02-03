#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
}

Point::Point(float value_x, float value_y) : x(value_x), y(value_y) {
}

Point::Point(const Point& point) {
	*this = point;
}

Point::~Point(void) {
}

Point&	Point::operator=(const Point& point) {
	this->x = point.x;
	this->y = point.y;
	return *this;
}

const Fixed&	Point::getX(void) const {
	return x;
}

const Fixed&	Point::getY(void) const {
	return y;
}

void	Point::setX(const Fixed& fixed) {
	x = fixed;
}

void	Point::setY(const Fixed& fixed) {
	y = fixed;
}
