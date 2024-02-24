#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Point	ab(Point::pointToDistanceVector(a, b));
	Point	pb(Point::pointToDistanceVector(point, b));

	Point	bc(Point::pointToDistanceVector(b, c));
	Point	pc(Point::pointToDistanceVector(point, c));

	Point	ca(Point::pointToDistanceVector(c, a));
	Point	pa(Point::pointToDistanceVector(point, a));
	
	Fixed	c1(ab.getX() * pb.getY() - ab.getY() *pb.getX());
	Fixed	c2(bc.getX() * pc.getY() - bc.getY() *pc.getX());
	Fixed	c3(ca.getX() * pa.getY() - ca.getY() *pa.getX());

	Fixed	fixed0(0);
	return (
		(fixed0 < c1 && fixed0 < c2 && fixed0 < c2)
		|| (c1 < fixed0 && c2 < fixed0 && c3 < fixed0)
	);
}
