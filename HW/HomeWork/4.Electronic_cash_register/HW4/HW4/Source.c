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

#define _CRT_SECURE_NO_WARNINGS

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
	int barcode[product][size], discount[product], price[product], number[product], check[ch_size], cheque_num = -1, n = 0;
	int n_product[product];// кол-во n-го товара
	int input = 1, output = 0, bar_input, uniq_flag = 0;
	char pr_name[product][15] = { {"Товар 1"}, {"Товар 2"}, {"Товар 3"}, {"Товар 4"}, {"Товар 5"} };
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
	printf("Для повторного вывода всех команд введите - 7\n");
	while (uniq_flag != 1)
	{
		int test_check = 0;
		for (int i = 0; i < product; i++)
		{
			for (int j = 0; j < size; j++)
			{
				barcode[i][j] = random_num(9, 1);
			}
		}
		for (int i = 0; i < product; i++)
		{
			int test = 0;
			for (int j = 0; j < size; j++)
			{
				if (barcode[i][j] == barcode[i + 1][j])
				{
					test += 1;
					if (test < size)
					{
						test_check += 1;
					}
				}
			}
		}
		if (test_check == product)
		{
			uniq_flag = 1;
		}
	}
	for (int i = 0; i < product; i++)
	{
		price[i] = random_num(10000, 1000);
	}
	for (int i = 0; i < product; i++)
	{
		if (price[i] >= 5000)
		{
			discount[i] = random_num(15, 1);
		}
		else if (price[i] >= 3000 && price[i] < 5000)
		{
			discount[i] = random_num(30, 1);
		}
		else
		{
			discount[i] = random_num(50, 1);
		}
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
			int bar_save = bar_input, del = 10;
			while (bar_input != 0)
			{
				if ((bar_input / del) > 10)
				{
					del *= 10;
				}
				else
				{
					bar_input = 0;
				}
			}
			int del_save = del;
			int bar_input_coincidences = 0;
			for (int i = 0; i < product + 2; i++)
			{
				if (bar_input_coincidences == size)
				{
					cheque_num = i - 1;
					break;
				}
				del = del_save;
				bar_input = bar_save;
				bar_input_coincidences = 0;
				int first_num = 0, num_check = -1, last_num = 0;
				for (int j = 0; j < size; j++)
				{
					if (first_num == 0)
					{
						num_check = bar_input / del;
						bar_input = bar_input % del;
						del /= 10;
						first_num += 1;
					}
					else if (last_num == 1)
					{
						num_check = bar_input % 10;
					}
					else if (first_num != 0 && last_num != 1)
					{
						num_check = (bar_input / del) % del;
						del /= 10;
						if (del == 1)
						{
							last_num += 1;
						}
					}
					if (num_check == barcode[i][j])
					{
						bar_input_coincidences += 1;
					}
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
			for (int i = 0; i < product; i++)
			{
				n_product[i] = 0;
			}
			for (int i = 0; i < ch_size; i++)
			{
				int z = check[i];
				n_product[z] += 1;
			}
			printf("\nВведите команду: ");
			scanf("%d", &input);
		}
		if (input == 5)
		{
			printf("Чек :\n");
			int out_num = -1, fin_price = 0;
			for (int i = 0; i < product; i++)
			{
				if (n_product[i] != 0)
				{
					for (int j = 0; j < size; j++)
					{
						printf("%d", barcode[i][j]);
					}
					printf("| %s ", pr_name[i]);
					printf("| Цена: %d ", price[i]);
					printf("| Скидка:%d", discount[i]);
					printf("| Кол-во товаров:%d\n", n_product[i]);
				}
			}
			printf("\nВведите команду: ");
			scanf("%d", &input);
		}
		if (input == 6)
		{
			int fan_price = -9;
			for (int i = 0; i < product; i++)
			{
				if (n_product[i] != 0)
				{
					fan_price = fan_price + ((price[check[i]] - (price[check[i]] * (discount[check[i]] * 0.01))) * n_product[i]);
				}
			}
			printf("К оплате с учётом скидок: %d", fan_price);
			printf("\nВведите команду: ");
			scanf("%d", &input);
		}
		if (input == 7)
		{
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