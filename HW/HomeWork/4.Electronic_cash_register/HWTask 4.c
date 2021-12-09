//Copyright 2021 Nedelin-Dmitry
/*
Каждый товар описывается штрих-кодом, наименованием, стоимостью за единицу товара, скидкой в процентах от стоимости. Скидки устанавливаются на каждый товар независимо (в диапазоне от 1 до 50%). Программа должна предоставлять следующие операции: 
1)вывод списка
2) «сканировать» очередной товар
3) вывести описание отсканированного товара
 4) добавить данные о товаре в чек
 5) сформировать чек за покупку
 6) рассчитать итоговую сумму к оплате.
 
 Описание работы:
 0)Генерирует массив размером product( кол-во товаров) на size ( длина штрих-кода)
 1)простой вывод через printf (повторный вывод через ввод "7')
 2)пользователь вводит штрих-код товара,программа проверяет ввод на соответствие и "запоминает" введённый товар
 3)выводит данные последнего товара
 4)добавляет в отдельный массив-чек штрих-код товара
 5)Просматривает все штрих-коды в массиве-чеке и выводит данные этих товаров
 6)Расчитывает цену по принципу
 Финальная цена += цена товара - (цена товара * скидку * 0.01)
 Повторяется на всех товарах из чека
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <locale.h>

#define size 4
#define product 5
#define ch_size 10
int random_num(int max, int min)
{
	int num;
	num = (rand() % (max - min + 1)) + min;
	return num;
}
int main()
{
	int barcode[product][size], discount[product], price[product], number[product], check[ch_size], cheque_num, n = 0;
	int input = 1, output = 0, bar_input, uniq_flag = 0;
	char pr_name[product][15] = {{"Товар 1"}, {"Товар 2"}, {"Товар 3"}, {"Товар 4"}, {"Товар 5"}};
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	for (int i = 0; i < ch_size; i++)
	{
		check[i] = -1;
	}
	printf("Для повторного вывода списка введите - 1\n");
	printf("Для сканирования товара введите - 2\n");
	printf("Для вывода описания отсканированого товара введите - 3\n");
	printf("Для того чтобы добавить товар в чек введите - 4\n");
	printf("Для вывода чека введите - 5\n");
	printf("Для вывода суммы оплаты введите - 6\n");
	printf("Для повторного вывода всех команд введите - 7");
	while(uniq_flag !=1){
		int test_check = 0;
		for (int i = 0; i < product; i++)
		{
			for (int j = 0; j < size; j++)
			{
				barcode[i][j] = random_num(9, 1);
			}
		}
		for(int i = 0; i < product; i++){
			int test = 0;
			for( int j = 0; j < size; j++){
				if(barcode[i][j] == barcode[i+1][j]){
					test += 1;
					if (test < size){
						test_check += 1;
					}
				}
			}
		}
		if (test_check == product){
			uniq_flag = 1;
		}
	}
	for (int i = 0; i < product; i++)
	{
		discount[i] = random_num(50, 1);
	}
	for (int i = 0; i < product; i++)
	{
		price[i] = random_num(10000, 1000);
	}
	while (input != 0)
	{
		if (input == 1)
		{
			printf("Список товаров:");
			int k = 0;
			for (int i = 0; i < product; i++)
			{
				printf("\n");
				for (int j = 0; j < size; j++)
				{
					printf("%d", barcode[i][j]);
					output += 1;
					if (output % 4 == 0)
					{
						printf("| %s ", pr_name[k]);
						printf("| Цена: %d ", price[k]);
						printf("| Скидка: %d ", discount[k]);
						k += 1;
					}
				}
			}
			printf("\nВведите команду: ");
			scanf("%d", &input);
		}
		if (input == 2)
		{
			printf("Введите код: ");
			scanf("%d", &bar_input); //cheque
			int num = 0, p = 0;
			for (int i = 0; i < product; i++)
			{
				num += 1;
				if (bar_input / 1000 == barcode[i][0])
				{
					if (((bar_input / 100) % 10) == barcode[i][1])
					{
						if (((bar_input / 10) % 10) == barcode[i][2])
						{
							if ((bar_input % 10) == barcode[i][3])
							{
								p += 1;
								cheque_num = i;
								printf("Товар просканирован\n");
							}
						}
					}
				}
				else if (num == 5 && p != 1)
				{
					printf("Товар не найден\n");
				}
			}
			printf("\nВведите команду: ");
			scanf("%d", &input);
		}
		if (input == 3)
		{
			for (int i = 0; i < size; i++)
			{
				printf("%d", barcode[cheque_num][i]);
			}
			printf("| %s ", pr_name[cheque_num]);
			printf("| Цена: %d ", price[cheque_num]);
			printf("| Скидка: %d ", discount[cheque_num]);
			printf("\nВведите команду: ");
			scanf("%d", &input);
		}
		if (input == 4)
		{
			check[n] = cheque_num;
			n += 1;
			printf("Товар добавлен");
			printf("\nВведите команду: ");
			scanf("%d", &input);
		}
		if (input == 5)
		{
			printf("Чек :\n");
			int out_num = -1, fin_price = 0;
			;
			for (int i = 0; i < ch_size; i++)
			{
				if (check[i] == -1)
				{
					break;
				}
				out_num = check[i];
				for (int j = 0; j < size; j++)
				{
					printf("%d", barcode[out_num][j]);
				}
				printf("| %s ", pr_name[out_num]);
				printf("| Цена: %d ", price[out_num]);
				printf("| Скидка:%d\n", discount[out_num]);
			}
			printf("\nВведите команду: ");
			scanf("%d", &input);
		}
		if (input == 6)
		{
			int fan_price = -2;
			for (int i = 0; i < ch_size; i++)
			{
				if (check[i] == -1)
				{
					break;
				}
				fan_price = fan_price + (price[check[i]] - (price[check[i]] * (discount[check[i]] * 0.01)));
			}
			printf("К оплате с учётом скидок: %d", fan_price);
				printf("\nВведите команду: ");
				scanf("%d", &input);
		}
		if (input == 7){
			printf("Для повторного вывода списка введите - 1\n");
	printf("Для сканирования товара введите - 2\n");
	printf("Для вывода описания отсканированого товара введите - 3\n");
	printf("Для того чтобы добавить товар в чек введите - 4\n");
	printf("Для вывода чека введите - 5\n");
	printf("Для вывода суммы оплаты введите - 6\n");
	printf("Для повторного вывода всех команд введите - 7");
	printf("\nВведите команду: ");
	scanf("%d", &input);
		}
	}

	return 0;
}