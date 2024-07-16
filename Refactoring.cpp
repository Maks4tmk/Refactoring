// Refactoring.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "shape.h"
#include "transform.h"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"


Shape shLine(static_cast<int>(Sh_Name::line), 1, 2, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
Shape shSquare(static_cast<int>(Sh_Name::sqr), 1, 2, 0, 3, 4, 0, 5, 6, 0, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
Shape shCube(static_cast<int>(Sh_Name::cube), 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24);
Shape shCircle(static_cast<int>(Sh_Name::circle), 1, 2, 3, 0);
Shape shCylinder(static_cast<int>(Sh_Name::cylinder), 1, 2, 3, 4);


TEST_CASE("Проверка класс Shape") {

	SECTION("Тест Line")
	{
		CHECK(shLine.getType() == 0);
		CHECK(shLine.x1 == 1);
		CHECK(shLine.y1 == 2);
		CHECK(shLine.x2 == 3);
		CHECK(shLine.y2 == 4);

		CHECK(shLine.getSquare() == 0);
		CHECK(shLine.getVolume() == 0);
	}


	SECTION("Тест Square")
	{
		CHECK(shSquare.getType() == 1);
		CHECK(shSquare.x1 == 1);
		CHECK(shSquare.y1 == 2);
		CHECK(shSquare.x2 == 3);
		CHECK(shSquare.y2 == 4);
		CHECK(shSquare.x3 == 5);
		CHECK(shSquare.y3 == 6);
		CHECK(shSquare.x4 == 7);
		CHECK(shSquare.y4 == 8);

		CHECK(shSquare.getSquare() == 4);
		CHECK(shSquare.getVolume() == 0);
	}


	SECTION("Тест Cube")
	{
		CHECK(shCube.getType() == 2);
		CHECK(shCube.x1 == 1); CHECK(shCube.x2 == 4); CHECK(shCube.x3 == 7);
		CHECK(shCube.y1 == 2); CHECK(shCube.y2 == 5); CHECK(shCube.y3 == 8);
		CHECK(shCube.z1 == 3); CHECK(shCube.z2 == 6); CHECK(shCube.z3 == 9);

		CHECK(shCube.x4 == 10); CHECK(shCube.x5 == 13); CHECK(shCube.x6 == 16);
		CHECK(shCube.y4 == 11); CHECK(shCube.y5 == 14); CHECK(shCube.y6 == 17);
		CHECK(shCube.z4 == 12); CHECK(shCube.z5 == 15); CHECK(shCube.z6 == 18);

		CHECK(shCube.x7 == 19); CHECK(shCube.x8 == 22);
		CHECK(shCube.y7 == 20); CHECK(shCube.y8 == 23);
		CHECK(shCube.z7 == 21); CHECK(shCube.z8 == 24);

		CHECK(shCube.getSquare() == 54);
		CHECK(shCube.getVolume() == 27);
	}

	SECTION("Тест Cylinder")
	{
		CHECK(shCylinder.getType() == 4);
		CHECK(shCylinder.x1 == 1);
		CHECK(shCylinder.y1 == 2);
		CHECK(shCylinder.getRadius() == 3);
		CHECK(shCylinder.getHeight() == 4);

		CHECK(shCylinder.getSquare() == 52.274333882308142);
		CHECK(shCylinder.getVolume() == 113.09733552923255);
	}

	SECTION("Тест Circle")
	{
		CHECK(shCircle.getType() == 3);
		CHECK(shCircle.x1 == 1);
		CHECK(shCircle.y1 == 2);
		CHECK(shCircle.getRadius() == 3);

		CHECK(shCircle.getSquare() == 28.274333882308138);
		CHECK(shCircle.getVolume() == 0);
	}
}


transform trLine(shLine);
transform trSquare(shSquare);
transform trCube(shCube);

TEST_CASE("Проверка класс transform") {
	SECTION("Тест trLine")
	{
		SECTION("shift") {
			Shape exLine = trLine.shift(1, 2, 3);

			CHECK(exLine.x1 == 2);
			CHECK(exLine.y1 == 4);
			CHECK(exLine.x2 == 4);
			CHECK(exLine.y2 == 6);
		}

		SECTION("scaleX") {
			Shape exLine = trLine.scaleX(2);

			CHECK(exLine.x1 == 4);
			CHECK(exLine.x2 == 8);

		}

		SECTION("scaleY") {
			Shape exLine = trLine.scaleY(3);

			CHECK(exLine.y1 == 12);
			CHECK(exLine.y2 == 18);
		}
		
		SECTION("scaleZ") {
			Shape exLine = trLine.scaleZ(4);

			CHECK(exLine.z1 == 0);
			CHECK(exLine.z2 == 0);

		}

		SECTION("scale") {
			Shape exLine = trLine.scale(5);

			CHECK(exLine.x1 == 0);
			CHECK(exLine.y1 == 2);
			CHECK(exLine.x2 == 1);
			CHECK(exLine.y2 == 3);
		}
	}




	SECTION("Тест trSquare")
	{
		SECTION("shift") {
			Shape exSquare = trSquare.shift(1, 2, 3);

			CHECK(exSquare.x1 == 2);
			CHECK(exSquare.y1 == 4);
			CHECK(exSquare.x2 == 4);
			CHECK(exSquare.y2 == 6);
			CHECK(exSquare.x3 == 6);
			CHECK(exSquare.y3 == 8);
			CHECK(exSquare.x4 == 8);
			CHECK(exSquare.y4 == 10);
		}

		SECTION("scaleX") {
			Shape exSquare = trSquare.scaleX(2);

			CHECK(exSquare.x1 == 4);
			CHECK(exSquare.x2 == 8);
			CHECK(exSquare.x3 == 12);
			CHECK(exSquare.x4 == 16);

		}

		SECTION("scaleY") {
			Shape exSquare = trSquare.scaleY(3);

			CHECK(exSquare.y1 == 12);
			CHECK(exSquare.y2 == 18);
			CHECK(exSquare.y3 == 24);
			CHECK(exSquare.y4 == 30);
		}

		SECTION("scaleZ") {
			Shape exSquare = trSquare.scaleZ(4);

			CHECK(exSquare.z1 == 0);
			CHECK(exSquare.z2 == 0);
			CHECK(exSquare.z3 == 0);
			CHECK(exSquare.z4 == 0);

		}

		SECTION("scale") {
			Shape exSquare = trSquare.scale(5);

			CHECK(exSquare.x1 == 0);
			CHECK(exSquare.y1 == 2);
			CHECK(exSquare.x2 == 1);
			CHECK(exSquare.y2 == 3);
			CHECK(exSquare.x3 == 2);
			CHECK(exSquare.y3 == 4);
			CHECK(exSquare.x4 == 3);
			CHECK(exSquare.y4 == 6);
		}
	}





	SECTION("Тест trCube")
	{
		SECTION("shift") {
			Shape exCube = trCube.shift(1, 2, 3);

			CHECK(exCube.x1 == 2); CHECK(exCube.x2 == 5); CHECK(exCube.x3 == 8);
			CHECK(exCube.y1 == 4); CHECK(exCube.y2 == 7); CHECK(exCube.y3 == 10);
			CHECK(exCube.z1 == 6); CHECK(exCube.z2 == 9); CHECK(exCube.z3 == 12);

			CHECK(exCube.x4 == 11); CHECK(exCube.x5 == 14); CHECK(exCube.x6 == 17);
			CHECK(exCube.y4 == 13); CHECK(exCube.y5 == 16); CHECK(exCube.y6 == 19);
			CHECK(exCube.z4 == 15); CHECK(exCube.z5 == 18); CHECK(exCube.z6 == 21);

			CHECK(exCube.x7 == 20); CHECK(exCube.x8 == 23);
			CHECK(exCube.y7 == 22); CHECK(exCube.y8 == 25);
			CHECK(exCube.z7 == 24); CHECK(exCube.z8 == 27);
		}

		SECTION("scaleX") {
			Shape exCube = trCube.scaleX(2);

			CHECK(exCube.x1 == 4);
			CHECK(exCube.x2 == 10);
			CHECK(exCube.x3 == 16);
			CHECK(exCube.x4 == 22);
			CHECK(exCube.x5 == 28);
			CHECK(exCube.x6 == 34);
			CHECK(exCube.x7 == 40);
			CHECK(exCube.x8 == 46);

		}

		SECTION("scaleY") {
			Shape exCube = trCube.scaleY(3);

			CHECK(exCube.y1 == 12);
			CHECK(exCube.y2 == 21);
			CHECK(exCube.y3 == 30);
			CHECK(exCube.y4 == 39);
			CHECK(exCube.y5 == 48);
			CHECK(exCube.y6 == 57);
			CHECK(exCube.y7 == 66);
			CHECK(exCube.y8 == 75);
		}

		SECTION("scaleZ") {
			Shape exCube = trCube.scaleZ(4);

			CHECK(exCube.z1 == 24);
			CHECK(exCube.z2 == 9);
			CHECK(exCube.z3 == 48);
			CHECK(exCube.z4 == 60);
			CHECK(exCube.z5 == 72);
			CHECK(exCube.z6 == 84);
			CHECK(exCube.z7 == 96);
			CHECK(exCube.z8 == 108);

		}

		SECTION("scale") {
			Shape exCube = trCube.scale(5);

			CHECK(exCube.x1 == 0); CHECK(exCube.x2 == 2); CHECK(exCube.x3 == 3);
			CHECK(exCube.y1 == 2); CHECK(exCube.y2 == 16); CHECK(exCube.y3 == 6);
			CHECK(exCube.z1 == 4); CHECK(exCube.z2 == 1); CHECK(exCube.z3 == 9);

			CHECK(exCube.x4 == 4); CHECK(exCube.x5 == 5); CHECK(exCube.x6 == 6);
			CHECK(exCube.y4 == 7); CHECK(exCube.y5 == 9); CHECK(exCube.y6 == 11);
			CHECK(exCube.z4 == 12); CHECK(exCube.z5 == 14); CHECK(exCube.z6 == 16);

			CHECK(exCube.x7 == 8); CHECK(exCube.x8 == 9);
			CHECK(exCube.y7 == 13); CHECK(exCube.y8 == 15);
			CHECK(exCube.z7 == 19); CHECK(exCube.z8 == 21);
		}
	}
}



int main(int argc, char* argv[])
{
	setlocale(LC_ALL,"ru");

	return Catch::Session().run(argc, argv);
}
