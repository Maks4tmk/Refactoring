#pragma once
#include<string>
#include <iostream>



class Shape
{
protected:
	struct Sh_coor
	{
		int x1 = 0, y1 = 0, z1 = 0;
		int x2 = 0, y2 = 0, z2 = 0;
		int x3 = 0, y3 = 0, z3 = 0;
		int x4 = 0, y4 = 0, z4 = 0;
		int x5 = 0, y5 = 0, z5 = 0;
		int x6 = 0, y6 = 0, z6 = 0;
		int x7 = 0, y7 = 0, z7 = 0;
		int x8 = 0, y8 = 0, z8 = 0;
	};

	Sh_coor coor;

	double volume = 0;
	double square = 0;
	double height = 0;
	double radius = 0;


public:
	Shape() = default;

	double getVolume();
	double getSquare();
	double getHeight();
	double getRadius();

	Sh_coor coor_f;

};

class Sh_Line : public Shape
{
public:
	Sh_Line() = default;

	Sh_Line(int _x1, int _y1, int _x2, int _y2);

	virtual void shift(int _m, int _n);
	virtual void scaleX(int _a);
	virtual void scaleY(int _d);
	virtual void scaleZ(int _e);
	virtual void scale(int _s);

};


class Sh_Sqr : public Sh_Line
{
public:
	Sh_Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4);

	void shift(int _m, int _n) override;
	void scaleX(int _a) override;
	void scaleY(int _d) override;
	void scaleZ(int _e) override;
	void scale(int _s) override;

};


class Sh_Cube : public Sh_Line
{
public:
	Sh_Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);

	void shift(int _m, int _n, int _k);
	void scaleX(int _a) override;
	void scaleY(int _d) override;
	void scaleZ(int _e) override;
	void scale(int _s) override;
};


class Sh_Circle : public Shape
{
public:
	Sh_Circle() = default;
	Sh_Circle(int _x1, int _y1, double _R);
};


class Sh_Cylinder : public Sh_Circle
{
public:
	Sh_Cylinder(int _x1, int _y1, double _R, double _H);
};
