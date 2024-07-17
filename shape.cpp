#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>


Sh_Line::Sh_Line(int _x1, int _y1, int _x2, int _y2)
{
	coor_f.x1 = coor.x1 = _x1; coor_f.y1 = coor.y1 = _y1;
	coor_f.x2 = coor.x2 = _x2; coor_f.y2 = coor.y2 = _y2;
	square = 0.;
	volume = 0.;
}

Sh_Sqr::Sh_Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4)
{
	coor.x1 = _x1; coor.y1 = _y1;
	coor.x2 = _x2; coor.y2 = _y2;
	coor.x3 = _x3; coor.y3 = _y3;
	coor.x4 = _x4; coor.y4 = _y4;
	square = pow((coor.x1 - coor.x2), 2) + pow((coor.y1 - coor.y2), 2);
	volume = 0.;
	coor_f = coor;
}



Sh_Cube::Sh_Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8)
{
	coor.x1 = _x1; coor.y1 = _y1; coor.z1 = _z1;
	coor.x2 = _x2; coor.y2 = _y2; coor.z2 = _z2;
	coor.x3 = _x3; coor.y3 = _y3; coor.z3 = _z3;
	coor.x4 = _x4; coor.y4 = _y4; coor.z4 = _z4;
	coor.x5 = _x5; coor.y5 = _y5; coor.z5 = _z5;
	coor.x6 = _x6; coor.y6 = _y6; coor.z6 = _z6;
	coor.x7 = _x7; coor.y7 = _y7; coor.z7 = _z7;
	coor.x8 = _x8; coor.y8 = _y8; coor.z8 = _z8;
	square = 6 * (pow((coor.x1 - coor.x2), 2) + pow((coor.y1 - coor.y2), 2));
	volume = 2 * (pow((coor.x1 - coor.x2), 2) + pow((coor.y1 - coor.y2), 2));
	coor_f = coor;
}

Sh_Circle::Sh_Circle(int _x1, int _y1, double _R)
{
	coor.x1 = _x1; coor.y1 = _y1;
	radius = _R;
	square = M_PI * _R * _R;
	volume = 0.;
	coor_f = coor;
}

Sh_Cylinder::Sh_Cylinder(int _x1, int _y1, double _R, double _H)
{
	coor.x1 = _x1; coor.y1 = _y1;
	radius = _R;
	height = _H;
	square = 2 * M_PI * _R * (_R + _H);
	volume = M_PI * _R * _R * _H;
	coor_f = coor;
}

double Shape::getVolume() { return volume; }
double Shape::getSquare() { return square; }
double Shape::getHeight() { return height; }
double Shape::getRadius() { return radius; }