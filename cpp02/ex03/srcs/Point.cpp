#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(float value_x, float value_y) : x(value_x), y(value_y) {}

Point::Point(const Point& point) : x(point.x), y(point.y) {}

Point::~Point(void) {}

Point&	Point::operator=(const Point& point) {
	if (this != &point) {
		this->x = point.x;
		this->y = point.y;
	}
	return *this;
}

const Fixed&	Point::getX(void) const {
	return x;
}

const Fixed&	Point::getY(void) const {
	return y;
}

void	Point::setX(const Fixed& x) {
	this->x = x;
}

void	Point::setY(const Fixed& y) {
	this->y = y;
}

Point	Point::pointToDistanceVector(const Point& p1, const Point& p2) {
	Point	tmp;

	tmp.setX(p1.getX() - p2.getX());
	tmp.setY(p1.getY() - p2.getY());
	return tmp;
}
