//Copyright 2021 Nedelin-Dmitry
/*
* ��������� ��������� 3 ����� � �������:
* 1.������� �������������� ���� �����
* 2.������� ��������� ���� �����
* 3.������� ������� ���� �����
* 4.������� ������ ���� �����
*/
#include<stdio.h>
#include<math.h>
int main() {
	int num_1, num_2, num_3;
	double output;
	printf("Input 3 numbers(space):\n");
	scanf_s("%d %d %d", &num_1, &num_2, &num_3);
	output = (num_1 + num_2 + num_3) / 3;
	printf("\n Arithmetical mean:n=%.2f", output);
	output = (num_1 * num_1 + num_2 * num_2 + num_3 * num_3) / 3;
	printf("\n Mean of the squares n=%.2f", output);
	output = (fabs(num_1) + fabs(num_2) + fabs(num_3)) / 3;
	printf("\n Secondary modules n=%.2f", output);
	output = (sqrt(num_1) + sqrt(num_2) + sqrt(num_3)) / 3;
	printf("\n Mean roots n=%.3f", output);
	return 0;

}