#ifndef CPP02_EX03_Point_H_
# define CPP02_EX03_Point_H_

#include "Fixed.hpp"

class Point {
private:
	Fixed	x;
	Fixed	y;

public:
	Point(void);
	Point(float, float);
	Point(const Point&);
	~Point(void);
	Point&			operator=(const Point&);

	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;
	void			setX(const Fixed&);
	void			setY(const Fixed&);
	static Point	PointToDistanceVector(const Point&, const Point&);

};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
