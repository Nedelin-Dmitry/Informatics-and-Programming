//Copyright 2021 Nedelin-Dmitry
/*
��������� ����������� ���� ������������ �� ����� "0" ��� ������

�������� �� ������������ ����� �������������
������������ �������� ���� �� ���� �������:
1)����������� �����:
���������� ��������� ����� ��������� �������� � ����������,����� ���� ����������� � ������ � ����� "�������" ��������� �����
2)������� ����� ���� �����:
���������� � ���������� ����� ������ ������� �������, ����� ���� "�������" ��� �������� �� 10
*/
#include <stdio.h>
int main() {
    int numm, inverse, option;
    int isWork = 1;
    while (isWork) {
        printf("\nInput number:");
        printf("\nfor exit input 0");
        int isError = 0;
        do {
            if (isError) {
                printf("Wrong input! Try again.");
            }
            printf("\nInput positive number:");
            scanf_s("%d", &numm);
            if (numm == 0) {
                isWork = 0;
                break;
            }
            isError = (numm <= 0);
        } while (isError);
        while (1) {
            printf("\n0 - EXIT\n1- invers number\n2- Sum of digits of a number\n");
            scanf_s("%d", &option);
            inverse = 0;
            if (option == 1 || option == 2 || option == 0) {
                break;
            }
            else {
                printf("Wrong input! Try again");
            }
        }
        if (option == 1) {
            while (numm) {
                inverse *= 10;
                inverse += (numm % 10);
                numm /= 10;
            }
        }
        if (option == 2) {
            while (numm) {
                inverse += numm % 10;
                numm /= 10;
            }
        }
        if (option == 1) {
            break;
        }
        if (isWork) {
            printf("\nResult:%d\n", inverse);
            printf("\nInput 0 in to EXIT");
        }
    }
    return 0;

}