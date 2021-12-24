//Copyright 2021 Nedelin Dmitry
/*
*��������� ���������� �������� ������������ ���� �����������
*�� �������� ������������� ������(���������� ������ ���������� � ������)
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Russian");
	double x1, x2, y1, y2, r1, r2, center_distance;
	printf("������� ���������� � ������ 1-� � 2-� �����������(����� ������)\n:");
	scanf("%lf %lf %lf", &x1, &y1, &r1);
	scanf("%lf %lf %lf", &x2, &y2, &r2);
	center_distance = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
	if (center_distance == 0) {
		printf("���������� ���������\n");
	}
	else if (center_distance > r1 - r2) {
		printf("���������� ������������\n");
	}
	else if (center_distance + r1 < r2 || center_distance + r2 < r1) {
		printf("���� ���������� ������ ������\n");
	}
	else if (center_distance > r1 + r2) {
		printf("���������� �� ������������\n");
	}
	else if (center_distance == r1 + r2) {
		printf("���������� �������� ���� �����");
	}
	return 0;

}


