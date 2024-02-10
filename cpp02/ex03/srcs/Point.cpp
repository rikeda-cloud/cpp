#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(float value_x, float value_y) : x(value_x), y(value_y) {}

Point::Point(const Point& point) {
	*this = point;
}

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

void	Point::setX(const Fixed& fixed_x) {
	x = fixed_x;
}

void	Point::setY(const Fixed& fixed_y) {
	y = fixed_y;
}

Point	Point::PointToDistanceVector(const Point& p1, const Point& p2) {
	Point	tmp;

	tmp.setX(p1.getX() - p2.getX());
	tmp.setY(p1.getY() - p2.getY());
	return tmp;
}
