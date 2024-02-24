#ifndef CPP02_EX03_Point_H_
# define CPP02_EX03_Point_H_

#include "Fixed.hpp"

class Point {
public:
	Point(void);
	Point(const float value_x, const float value_y);
	Point(const Point&);
	~Point(void);
	Point&			operator=(const Point&);

	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;
	void			setX(const Fixed&);
	void			setY(const Fixed&);
	static Point	pointToDistanceVector(const Point&, const Point&);

private:
	const Fixed	x;
	const Fixed	y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
