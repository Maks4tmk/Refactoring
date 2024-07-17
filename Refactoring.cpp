// Refactoring.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "shape.h"
#include "transform.h"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"


Sh_Line shLine(1, 2, 3, 4);
Sh_Sqr shSquare(1, 2, 3, 4, 5, 6, 7, 8);
Sh_Cube shCube(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24);
Sh_Circle shCircle(1, 2, 3);
Sh_Cylinder shCylinder(1, 2, 3, 4);


TEST_CASE("Проверка класс Shape") {

	SECTION("Тест Line")
	{
		CHECK(shLine.coor_f.x1 == 1);
		CHECK(shLine.coor_f.y1 == 2);
		CHECK(shLine.coor_f.x2 == 3);
		CHECK(shLine.coor_f.y2 == 4);

		CHECK(shLine.getSquare() == 0);
		CHECK(shLine.getVolume() == 0);
	}


	SECTION("Тест Square")
	{
		CHECK(shSquare.coor_f.x1 == 1);
		CHECK(shSquare.coor_f.y1 == 2);
		CHECK(shSquare.coor_f.x2 == 3);
		CHECK(shSquare.coor_f.y2 == 4);
		CHECK(shSquare.coor_f.x3 == 5);
		CHECK(shSquare.coor_f.y3 == 6);
		CHECK(shSquare.coor_f.x4 == 7);
		CHECK(shSquare.coor_f.y4 == 8);

		CHECK(shSquare.getSquare() == 8);
		CHECK(shSquare.getVolume() == 0);
	}


	SECTION("Тест Cube")
	{
		CHECK(shCube.coor_f.x1 == 1); CHECK(shCube.coor_f.x2 == 4); CHECK(shCube.coor_f.x3 == 7);
		CHECK(shCube.coor_f.y1 == 2); CHECK(shCube.coor_f.y2 == 5); CHECK(shCube.coor_f.y3 == 8);
		CHECK(shCube.coor_f.z1 == 3); CHECK(shCube.coor_f.z2 == 6); CHECK(shCube.coor_f.z3 == 9);

		CHECK(shCube.coor_f.x4 == 10); CHECK(shCube.coor_f.x5 == 13); CHECK(shCube.coor_f.x6 == 16);
		CHECK(shCube.coor_f.y4 == 11); CHECK(shCube.coor_f.y5 == 14); CHECK(shCube.coor_f.y6 == 17);
		CHECK(shCube.coor_f.z4 == 12); CHECK(shCube.coor_f.z5 == 15); CHECK(shCube.coor_f.z6 == 18);

		CHECK(shCube.coor_f.x7 == 19); CHECK(shCube.coor_f.x8 == 22);
		CHECK(shCube.coor_f.y7 == 20); CHECK(shCube.coor_f.y8 == 23);
		CHECK(shCube.coor_f.z7 == 21); CHECK(shCube.coor_f.z8 == 24);

		CHECK(shCube.getSquare() == 108);
		CHECK(shCube.getVolume() == 36);
	}

	SECTION("Тест Cylinder")
	{
		CHECK(shCylinder.coor_f.x1 == 1);
		CHECK(shCylinder.coor_f.y1 == 2);
		CHECK(shCylinder.getRadius() == 3);
		CHECK(shCylinder.getHeight() == 4);

		CHECK(shCylinder.getSquare() == 131.94689145077132);
		CHECK(shCylinder.getVolume() == 113.09733552923255);
	}

	SECTION("Тест Circle")
	{
		CHECK(shCircle.coor_f.x1 == 1);
		CHECK(shCircle.coor_f.y1 == 2);
		CHECK(shCircle.getRadius() == 3);

		CHECK(shCircle.getSquare() == 28.274333882308138);
		CHECK(shCircle.getVolume() == 0);
	}
}


TEST_CASE("Проверка класс transform") {
	SECTION("Тест trLine")
	{
		SECTION("shift") {
			shLine.shift(1, 2);

			CHECK(shLine.coor_f.x1 == 2);
			CHECK(shLine.coor_f.y1 == 4);
			CHECK(shLine.coor_f.x2 == 4);
			CHECK(shLine.coor_f.y2 == 6);
		}

		SECTION("scaleX") {
			shLine.scaleX(2);

			CHECK(shLine.coor_f.x1 == 4);
			CHECK(shLine.coor_f.x2 == 8);

		}

		SECTION("scaleY") {
			shLine.scaleY(3);

			CHECK(shLine.coor_f.y1 == 12);
			CHECK(shLine.coor_f.y2 == 18);
		}
		
		SECTION("scaleZ") {
			shLine.scaleZ(4);

			CHECK(shLine.coor_f.z1 == 0);
			CHECK(shLine.coor_f.z2 == 0);

		}

		SECTION("scale") {
			shLine.scale(5);

			CHECK(shLine.coor_f.x1 == 0);
			CHECK(shLine.coor_f.y1 == 2);
			CHECK(shLine.coor_f.x2 == 1);
			CHECK(shLine.coor_f.y2 == 3);
		}
	}




	SECTION("Тест trSquare")
	{
		SECTION("shift") {
			shSquare.shift(1, 2);

			CHECK(shSquare.coor_f.x1 == 2);
			CHECK(shSquare.coor_f.y1 == 4);
			CHECK(shSquare.coor_f.x2 == 4);
			CHECK(shSquare.coor_f.y2 == 6);
			CHECK(shSquare.coor_f.x3 == 6);
			CHECK(shSquare.coor_f.y3 == 8);
			CHECK(shSquare.coor_f.x4 == 8);
			CHECK(shSquare.coor_f.y4 == 10);
		}

		SECTION("scaleX") {
			shSquare.scaleX(2);

			CHECK(shSquare.coor_f.x1 == 4);
			CHECK(shSquare.coor_f.x2 == 8);
			CHECK(shSquare.coor_f.x3 == 12);
			CHECK(shSquare.coor_f.x4 == 16);

		}

		SECTION("scaleY") {
			shSquare.scaleY(3);

			CHECK(shSquare.coor_f.y1 == 12);
			CHECK(shSquare.coor_f.y2 == 18);
			CHECK(shSquare.coor_f.y3 == 24);
			CHECK(shSquare.coor_f.y4 == 30);
		}

		SECTION("scaleZ") {
			shSquare.scaleZ(4);

			CHECK(shSquare.coor_f.z1 == 0);
			CHECK(shSquare.coor_f.z2 == 0);
			CHECK(shSquare.coor_f.z3 == 0);
			CHECK(shSquare.coor_f.z4 == 0);

		}

		SECTION("scale") {
			shSquare.scale(5);

			CHECK(shSquare.coor_f.x1 == 0);
			CHECK(shSquare.coor_f.y1 == 2);
			CHECK(shSquare.coor_f.x2 == 1);
			CHECK(shSquare.coor_f.y2 == 3);
			CHECK(shSquare.coor_f.x3 == 2);
			CHECK(shSquare.coor_f.y3 == 4);
			CHECK(shSquare.coor_f.x4 == 3);
			CHECK(shSquare.coor_f.y4 == 6);
		}
	}





	SECTION("Тест trCube")
	{
		SECTION("shift") {
			shCube.shift(1, 2, 3);

			CHECK(shCube.coor_f.x1 == 2); CHECK(shCube.coor_f.x2 == 5); CHECK(shCube.coor_f.x3 == 8);
			CHECK(shCube.coor_f.y1 == 4); CHECK(shCube.coor_f.y2 == 7); CHECK(shCube.coor_f.y3 == 10);
			CHECK(shCube.coor_f.z1 == 6); CHECK(shCube.coor_f.z2 == 9); CHECK(shCube.coor_f.z3 == 12);

			CHECK(shCube.coor_f.x4 == 11); CHECK(shCube.coor_f.x5 == 14); CHECK(shCube.coor_f.x6 == 17);
			CHECK(shCube.coor_f.y4 == 13); CHECK(shCube.coor_f.y5 == 16); CHECK(shCube.coor_f.y6 == 19);
			CHECK(shCube.coor_f.z4 == 15); CHECK(shCube.coor_f.z5 == 18); CHECK(shCube.coor_f.z6 == 21);

			CHECK(shCube.coor_f.x7 == 20); CHECK(shCube.coor_f.x8 == 23);
			CHECK(shCube.coor_f.y7 == 22); CHECK(shCube.coor_f.y8 == 25);
			CHECK(shCube.coor_f.z7 == 24); CHECK(shCube.coor_f.z8 == 27);
		}

		SECTION("scaleX") {
			shCube.scaleX(2);

			CHECK(shCube.coor_f.x1 == 4);
			CHECK(shCube.coor_f.x2 == 10);
			CHECK(shCube.coor_f.x3 == 16);
			CHECK(shCube.coor_f.x4 == 22);
			CHECK(shCube.coor_f.x5 == 28);
			CHECK(shCube.coor_f.x6 == 34);
			CHECK(shCube.coor_f.x7 == 40);
			CHECK(shCube.coor_f.x8 == 46);

		}

		SECTION("scaleY") {
			shCube.scaleY(3);

			CHECK(shCube.coor_f.y1 == 12);
			CHECK(shCube.coor_f.y2 == 21);
			CHECK(shCube.coor_f.y3 == 30);
			CHECK(shCube.coor_f.y4 == 39);
			CHECK(shCube.coor_f.y5 == 48);
			CHECK(shCube.coor_f.y6 == 57);
			CHECK(shCube.coor_f.y7 == 66);
			CHECK(shCube.coor_f.y8 == 75);
		}

		SECTION("scaleZ") {
			shCube.scaleZ(4);

			CHECK(shCube.coor_f.z1 == 24);
			CHECK(shCube.coor_f.z2 == 36);
			CHECK(shCube.coor_f.z3 == 48);
			CHECK(shCube.coor_f.z4 == 60);
			CHECK(shCube.coor_f.z5 == 72);
			CHECK(shCube.coor_f.z6 == 84);
			CHECK(shCube.coor_f.z7 == 96);
			CHECK(shCube.coor_f.z8 == 108);

		}

		SECTION("scale") {
			shCube.scale(5);

			CHECK(shCube.coor_f.x1 == 0); CHECK(shCube.coor_f.x2 == 2); CHECK(shCube.coor_f.x3 == 3);
			CHECK(shCube.coor_f.y1 == 2); CHECK(shCube.coor_f.y2 == 4); CHECK(shCube.coor_f.y3 == 6);
			CHECK(shCube.coor_f.z1 == 4); CHECK(shCube.coor_f.z2 == 7); CHECK(shCube.coor_f.z3 == 9);

			CHECK(shCube.coor_f.x4 == 4); CHECK(shCube.coor_f.x5 == 5); CHECK(shCube.coor_f.x6 == 6);
			CHECK(shCube.coor_f.y4 == 7); CHECK(shCube.coor_f.y5 == 9); CHECK(shCube.coor_f.y6 == 11);
			CHECK(shCube.coor_f.z4 == 12); CHECK(shCube.coor_f.z5 == 14); CHECK(shCube.coor_f.z6 == 16);

			CHECK(shCube.coor_f.x7 == 8); CHECK(shCube.coor_f.x8 == 9);
			CHECK(shCube.coor_f.y7 == 13); CHECK(shCube.coor_f.y8 == 15);
			CHECK(shCube.coor_f.z7 == 19); CHECK(shCube.coor_f.z8 == 21);
		}
	}
}



int main(int argc, char* argv[])
{
	setlocale(LC_ALL,"ru");

	return Catch::Session().run(argc, argv);
}
