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


void Sh_Line::shift(int _m, int _n)
{
	coor.x1 += _m; coor.y1 += _n;
	coor.x2 += _m; coor.y2 += _n;
	coor_f = coor;
}

void Sh_Line::scaleX(int _a)
{
	coor.x1 *= _a;
	coor.x2 *= _a;
	coor_f = coor;
}

void Sh_Line::scaleY(int _d)
{
	coor.y1 *= _d;
	coor.y2 *= _d;
	coor_f = coor;
}

void Sh_Line::scaleZ(int _e)
{
	coor.z1 *= _e;
	coor.z2 *= _e;
	coor_f = coor;
}

void Sh_Line::scale(int _s)
{
	coor.x1 /= _s; coor.y1 /= _s;
	coor.x2 /= _s; coor.y2 /= _s;
	coor_f = coor;
}

void Sh_Sqr::shift(int _m, int _n)
{
	coor.x1 += _m; coor.y1 += _n;
	coor.x2 += _m; coor.y2 += _n;
	coor.x3 += _m; coor.y3 += _n;
	coor.x4 += _m; coor.y4 += _n;
	coor_f = coor;
}

void Sh_Sqr::scaleX(int _a)
{
	coor.x1 *= _a;
	coor.x2 *= _a;
	coor.x3 *= _a;
	coor.x4 *= _a;
	coor_f = coor;
}

void Sh_Sqr::scaleY(int _d)
{
	coor.y1 *= _d;
	coor.y2 *= _d;
	coor.y3 *= _d;
	coor.y4 *= _d;
	coor_f = coor;
}

void Sh_Sqr::scaleZ(int _e)
{
	coor.z1 *= _e;
	coor.z2 *= _e;
	coor.z3 *= _e;
	coor.z4 *= _e;
	coor_f = coor;
}

void Sh_Sqr::scale(int _s)
{
	coor.x1 /= _s; coor.y1 /= _s;
	coor.x2 /= _s; coor.y2 /= _s;
	coor.x3 /= _s; coor.y3 /= _s;
	coor.x4 /= _s; coor.y4 /= _s;
	coor_f = coor;
}

void Sh_Cube::shift(int _m, int _n, int _k)
{
	coor.x1 += _m; coor.y1 += _n; coor.z1 += _k;
	coor.x2 += _m; coor.y2 += _n; coor.z2 += _k;
	coor.x3 += _m; coor.y3 += _n; coor.z3 += _k;
	coor.x4 += _m; coor.y4 += _n; coor.z4 += _k;
	coor.x5 += _m; coor.y5 += _n; coor.z5 += _k;
	coor.x6 += _m; coor.y6 += _n; coor.z6 += _k;
	coor.x7 += _m; coor.y7 += _n; coor.z7 += _k;
	coor.x8 += _m; coor.y8 += _n; coor.z8 += _k;
	coor_f = coor;
}

void Sh_Cube::scaleX(int _a)
{
	coor.x1 *= _a;
	coor.x2 *= _a;
	coor.x3 *= _a;
	coor.x4 *= _a;
	coor.x5 *= _a;
	coor.x6 *= _a;
	coor.x7 *= _a;
	coor.x8 *= _a;
	coor_f = coor;
}

void Sh_Cube::scaleY(int _d)
{
	coor.y1 *= _d;
	coor.y2 *= _d;
	coor.y3 *= _d;
	coor.y4 *= _d;
	coor.y5 *= _d;
	coor.y6 *= _d;
	coor.y7 *= _d;
	coor.y8 *= _d;
	coor_f = coor;
}

void Sh_Cube::scaleZ(int _e)
{
	coor.z1 *= _e;
	coor.z2 *= _e;
	coor.z3 *= _e;
	coor.z4 *= _e;
	coor.z5 *= _e;
	coor.z6 *= _e;
	coor.z7 *= _e;
	coor.z8 *= _e;
	coor_f = coor;
}

void Sh_Cube::scale(int _s)
{
	coor.x1 /= _s; coor.y1 /= _s; coor.z1 /= _s;
	coor.x2 /= _s; coor.y2 /= _s; coor.z2 /= _s;
	coor.x3 /= _s; coor.y3 /= _s; coor.z3 /= _s;
	coor.x4 /= _s; coor.y4 /= _s; coor.z4 /= _s;
	coor.x5 /= _s; coor.y5 /= _s; coor.z5 /= _s;
	coor.x6 /= _s; coor.y6 /= _s; coor.z6 /= _s;
	coor.x7 /= _s; coor.y7 /= _s; coor.z7 /= _s;
	coor.x8 /= _s; coor.y8 /= _s; coor.z8 /= _s;
	coor_f = coor;
}
