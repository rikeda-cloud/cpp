#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const float value_x, const float value_y) : x(value_x), y(value_y) {}

Point::Point(const Point& point) : x(point.x), y(point.y) {}

Point::~Point(void) {}

Point&	Point::operator=(const Point& point) {
	if (this != &point) {
		const_cast<Fixed&>(this->x) = point.x;
		const_cast<Fixed&>(this->y) = point.y;
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
	const_cast<Fixed&>(this->x) = x;
}

void	Point::setY(const Fixed& y) {
	const_cast<Fixed&>(this->y) = y;
}

Point	Point::pointToDistanceVector(const Point& p1, const Point& p2) {
	Point	distance_vector;

	distance_vector.setX(p1.getX() - p2.getX());
	distance_vector.setY(p1.getY() - p2.getY());
	return distance_vector;
}
