//Copyright 2021 Nedelin-Dmitry
//�� ���� ������� ���� �� ������, ��������� ������������ ����������� ���-�� ����� ������� ����� ������ �� ������ � ������� ���
#include <stdio.h>
#include <locale.h>
int main() {
	int price, coins = 0;
	setlocale(LC_ALL, "Russian");
	printf("������� ������ �� �����:");
	scanf_s("%d", &price);
	while ((price / 25) >= 1) {
		price -= 25;
		coins += 1;
	}
	while ((price / 10) >= 1) {
		price -= 10;
		coins += 1;
	}
	while ((price / 5) >= 1) {
		price -= 5;
		coins += 1;
	}
	while (price >= 1) {
		price -= 1;
		coins += 1;
	}
	printf("����� ��������� �����: %d", coins);
	return 0;

}