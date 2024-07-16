// Refactoring.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "shape.h"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"


Shape Line(0, 1, 2, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
Shape Square(1, 1, 2, 0, 3, 4, 0, 5, 6, 0, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
Shape Cube(2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24);
Shape Circle(3, 1, 2, 3, 4);
Shape Cylinder(4, 0, 0, 0, 1);


TEST_CASE("Проверка Line") {
	REQUIRE(Line.type == 0);
	REQUIRE(Line.x1 == 1);
	REQUIRE(Line.y1 == 2);
	REQUIRE(Line.x2 == 3);
	REQUIRE(Line.y2 == 4);
	REQUIRE(Line.square == 0);
	REQUIRE(Line.volume == 0);
}

TEST_CASE("Проверка Square") {
	REQUIRE(Square.type == 1);
	REQUIRE(Square.x1 == 1);
	REQUIRE(Square.y1 == 2);
	REQUIRE(Square.x2 == 3);
	REQUIRE(Square.y2 == 4);
	REQUIRE(Square.x3 == 5);
	REQUIRE(Square.y3 == 6);
	REQUIRE(Square.x4 == 7);
	REQUIRE(Square.y4 == 8);
}

TEST_CASE("Проверка Cube") {
	REQUIRE(Cube.type == 2);
	REQUIRE(Cube.x1 == 1); REQUIRE(Cube.x2 == 4); REQUIRE(Cube.x3 == 7);
	REQUIRE(Cube.y1 == 2); REQUIRE(Cube.y2 == 5); REQUIRE(Cube.y3 == 8);
	REQUIRE(Cube.z1 == 3); REQUIRE(Cube.z2 == 6); REQUIRE(Cube.z3 == 9);

	REQUIRE(Cube.x4 == 10); REQUIRE(Cube.x5 == 13); REQUIRE(Cube.x6 == 16);
	REQUIRE(Cube.y4 == 11); REQUIRE(Cube.y5 == 14); REQUIRE(Cube.y6 == 17);
	REQUIRE(Cube.z4 == 12); REQUIRE(Cube.z5 == 15); REQUIRE(Cube.z6 == 18);

	REQUIRE(Cube.x7 == 19); REQUIRE(Cube.x8 == 22);
	REQUIRE(Cube.y7 == 20); REQUIRE(Cube.y8 == 23);
	REQUIRE(Cube.z7 == 21); REQUIRE(Cube.z8 == 24);
}

TEST_CASE("Проверка Circle") {
	REQUIRE(Circle.type == 3);
	REQUIRE(Circle.x1 == 1);
	REQUIRE(Circle.y1 == 2);
	REQUIRE(Circle.radius == 3);
	REQUIRE(Circle.height == 4);
	
}





int main(int argc, char* argv[])
{
	setlocale(LC_ALL,"ru");

	return Catch::Session().run(argc, argv);
}
