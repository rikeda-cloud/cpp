#include "Point.hpp"
#include "Fixed.hpp"

Point	point_to_vector(const Point& p1, const Point& p2) {
	Point	tmp;

	tmp.setX(p1.getX() - p2.getX());
	tmp.setY(p1.getY() - p2.getY());
	return tmp;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Point	ab(point_to_vector(a, b));
	Point	bp(point_to_vector(point, b));

	Point	bc(point_to_vector(b, c));
	Point	cp(point_to_vector(point, c));

	Point	ca(point_to_vector(c, a));
	Point	ap(point_to_vector(point, a));
	
	Fixed	c1 = ab.getX() * bp.getY() - ab.getY() *bp.getX();
	Fixed	c2 = bc.getX() * cp.getY() - bc.getY() *cp.getX();
	Fixed	c3 = ca.getX() * ap.getY() - ca.getY() *ap.getX();

	return (
		(c1 > Fixed(0) && c2 > Fixed(0) && c3 > Fixed(0))
		|| (c1 < Fixed(0) && c2 < Fixed(0) && c3 < Fixed(0))
	);
}
