//Copyright 2021 Nedelin-Dmitry
/* ����������� ������
������:
(1,2,3,4,5,6,7,8)->(5,6,7,8,1,2,3,4)
����������� 2-�� ���������
	1.� ���. ��������
	2. ��� ���. �������
	1)��������� ������ �������� 3-��� ������� ������ ��������� 2-��
����� ��������� ������ �������� 3-��� �������  ������ ��������� 2-��
	2)��������� 1-� ��������,������ 1-� �� ������,������ �� ����������� ������
*/
#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int* mass_1, * mass_2, * mass_3, save, size;
	// ������ 3 �������, ���������� ��� ���������� ��������
	int max = 9, min = 1, i;
	// max � min ��� �������
	int p = 0; // ��� ������������ ���������� 3-�� �������
	printf("������� ������ �������(������ �����): ");
	scanf_s("%d", &size);
	mass_1 = (int*)malloc(size * sizeof(int));
	mass_2 = (int*)malloc(size * sizeof(int));
	mass_3 = (int*)malloc(size * sizeof(int));
	printf("��� �������:\n");
	for (i = 0; i < size; i++) {
		mass_1[i] = i + 1;
		mass_2[i] = mass_1[i];
	}
	//��� �������
	for (i = 0; i < size; i++) {
		printf("%d ", mass_1[i]);
	}
	for (i = 0; i < (size / 2); i++) {
		save = mass_1[i];
		mass_1[i] = mass_1[size / 2 + i];
		mass_1[size / 2 + i] = save;
	}
	printf("\n");
	for (i = 0; i < size; i++) {
		printf("%d ", mass_1[i]);
	}
	//� �������������� ��������
	printf("\n������� � ���. ��������:\n");
	for (i = 0; i < size; i++) {
		printf("%d ", mass_2[i]);
	}
	for (i = (size / 2); i < size; i++) {
		mass_3[p] = mass_2[i];
		p += 1;
	}
	for (i = 0; i < (size / 2); i++) {
		mass_3[p] = mass_2[i];
		p += 1;
	}
	printf("\n");
	for (i = 0; i < size; i++) {
		printf("%d ", mass_3[i]);
	}
	return 0;

}