//Copyright 2021 Nedelin Dmitry
/*
*Программа определяет взаимное расположение двух окружностей
*По введённым пользователем данным(координаты центра окружности и радиус)
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Russian");
	double x1, x2, y1, y2, r1, r2, center_distance;
	printf("Введите координаты и радиус 1-й и 2-й окружностей(через пробел)\n:");
	scanf("%lf %lf %lf", &x1, &y1, &r1);
	scanf("%lf %lf %lf", &x2, &y2, &r2);
	center_distance = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
	if (center_distance == 0) {
		printf("Окружности совпадают\n");
	}
	else if (center_distance > r1 - r2) {
		printf("Окружности пересекаются\n");
	}
	else if (center_distance + r1 < r2 || center_distance + r2 < r1) {
		printf("Одна окружность внутри другой\n");
	}
	else if (center_distance > r1 + r2) {
		printf("Окружности не пересекаются\n");
	}
	else if (center_distance == r1 + r2) {
		printf("Окружности касаются друг друга");
	}
	return 0;

}


