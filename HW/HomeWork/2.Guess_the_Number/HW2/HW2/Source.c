//Copyright 2021 Nedelin-Dmitry
/*
Пользователь воодит кол-во бюджетных мест и кол-во претендентов
Программа создаёт 3 массива с размером равным кол-ву участников
И заполняет их случайными числами(результат по 3-м экзаменам)
А так-же считает сумму трёх экзаменов для определённого претендента
После чего выводит порядковый номер претендента и его результаты по 3-м экзаменам
После находит максимальный результат среди всех участников, запоминает его номер и результат,
Для того, того чтобы найти следующий по величине,обнуляет наибольший и ищет следующий максимальный результат
В конце выводит проходной балл и номер поступивших
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
	int size, n, i, p = 0;//размер массивов и кол-во поступивших
	int max = 100, min = 30, prb = 0;// max и min результат экзаменов; проходной балл
	int m_ege = 0, nm_ege, * max_ege;// максимальный результат егэ и его номер ; nm-массив для сохранения номеров поступивших
	printf("Введите кол-во бюджетных мест и кол-во участников: ");
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
	printf("Проходной балл=%d\n", (prb / n));
	printf("Номера прошедших:");
	for (i = 0; i < n; i++) {
		printf("%d ", nm[i] + 1);
	}
	return 0;

}