//Copyright 2021 Nedelin-Dmitry
/*
Просим пользователя ввести размер числа
После ввода генерируем массив размепом size, заполняем его "мусором"
С помощью счётчика уникальных чисел uniq_count заполняем массив неповторяющимися числами
Просим игрока отгадать число
Проверяем последнюю цифру числа и его позицию
При совпадении позиции и числа увеличиваем кол-во "быков" на 1
При совпадении только значения числа - увеличиваем кол-во "коров" на 1
После уменьшаем разряд числа на 1(/= 10) и значение position
Если игрок отгадал число - программа завершается
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>
#include<malloc.h>
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int size, * mass_uniq, * check_input, random_number, i, uniq_pos = 0, input;
	int max = 9, min = 1, uniq_count = 0, position, input_err = 0;
	while (1) {
		printf("Введите длину загадываемого числа(от 2 до 5): ");
		scanf("%d", &size);
		if (size >= 2 && size <= 5) {
			mass_uniq = (int*)malloc(size * sizeof(int));
			check_input = (int*)malloc(size * sizeof(int));
			break;
		}
		else {
			printf("Ошибка ввода, попробуйте ещё раз.\n");
		}
	}
	for (i = 0; i < size; i++) {
		mass_uniq[i] = 999;
		check_input[i] = 99;
	}
	while (uniq_count != size) {
		random_number = rand() % (max - min + 1) + min;
		int c = 0;
		for (i = 0; i < size; i++) {
			if (random_number != mass_uniq[i]) {
				c += 1;
				if (c == size) {
					uniq_count += 1;
					mass_uniq[uniq_pos] = random_number;
					uniq_pos += 1;
				}
			}
		}
	}
	printf("\n");
	while (1) {
		printf("\nПопытайтесь угадать число(Числа не должны повторяться):");
		scanf("%d", &input);
		input_err = 0;
		int input_test = input, check_num;
		for (i = 0; i < size; i++) {
			check_input[i] = input_test % 10;
			input_test /= 10;
		}
		for (i = 0; i < size; i++) {
			if (check_input[i] > 9 || check_input[i] == 0) {
				input_err = 1;
			}
		}
		for (i = 0; i < size; i++) {
			check_num = 0;
			for (int j = 0; j < size; j++) {
				if (check_input[i] == check_input[j]) {
					check_num += 1;
					if (check_num > 1) {
						input_err = 1;
					}
				}
			}
		}
		if (input_err == 1) {
			printf("\nОшибка ввода");
		}
		if (input_err == 0) {
			position = size;
			int cow = 0;
			int bull = 0;
			while (input > 0) {
				int k = input % 10;
				input /= 10;
				position -= 1;
				for (i = 0; i < size; i++) {
					if (k == mass_uniq[i] && position == i) {
						bull += 1;
					}
					else if (k == mass_uniq[i] && position != i) {
						cow += 1;
					}
				}
			}
			printf("Кол-во коров:%d", cow);
			printf("\nКол-во быков:%d", bull);
			if (bull == size) {
				break;
			}
		}
	}
	return 0;

}