//Copyright 2021 Nedelin-Dmitry
/*
������������ ������ ���-�� ��������� ���� � ���-�� ������������
��������� ������ 3 ������� � �������� ������ ���-�� ����������
� ��������� �� ���������� �������(��������� �� 3-� ���������)
� ���-�� ������� ����� ��� ��������� ��� ������������ �����������
����� ���� ������� ���������� ����� ����������� � ��� ���������� �� 3-� ���������
����� ������� ������������ ��������� ����� ���� ����������, ���������� ��� ����� � ���������,
��� ����, ���� ����� ����� ��������� �� ��������,�������� ���������� � ���� ��������� ������������ ���������
� ����� ������� ��������� ���� � ����� �����������
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<locale.h>
#include<stdlib.h>
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int* eg1, * eg2, * eg3, * nm;
	int size, n, i, p = 0;//������ �������� � ���-�� �����������
	int max = 100, min = 30, prb = 0;// max � min ��������� ���������; ��������� ����
	int m_ege = 0, nm_ege, * max_ege;// ������������ ��������� ��� � ��� ����� ; nm-������ ��� ���������� ������� �����������
	printf("������� ���-�� ��������� ���� � ���-�� ����������: ");
	scanf("%d %d", &n, &size);
	int n1 = n;
	eg1 = (int*)malloc(size * sizeof(int));
	eg2 = (int*)malloc(size * sizeof(int));
	eg3 = (int*)malloc(size * sizeof(int));
	nm = (int*)malloc(n * sizeof(int));
	max_ege = (int*)malloc(size * sizeof(int));
	for (i = 0; i < size; i++) {
		eg1[i] = (rand() % (max - min + 1) + min);
		eg2[i] = (rand() % (max - min + 1) + min);
		eg3[i] = (rand() % (max - min + 1) + min);
		max_ege[i] = (eg1[i] + eg2[i] + eg3[i]);
	}
	for (i = 0; i < size; i++) {
		printf("%d %d %d %d\n", i + 1, eg1[i], eg2[i], eg3[i]);
	}
	while (n1 != 0) {
		for (i = 0; i < size; i++) {
			if (max_ege[i] > m_ege) {
				m_ege = max_ege[i];
				nm_ege = i;
			}
		}
		prb += m_ege;
		nm[p] = nm_ege;
		p += 1;
		n1 -= 1;
		for (i = 0; i < size; i++) {
			if (max_ege[i] == m_ege) {
				max_ege[i] = 0;
			}
		}
		m_ege = 0;
	}
	printf("��������� ����=%d\n", (prb / n));
	printf("������ ���������:");
	for (i = 0; i < n; i++) {
		printf("%d ", nm[i] + 1);
	}
	return 0;

}