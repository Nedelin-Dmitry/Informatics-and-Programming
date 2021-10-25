//Copyright 2021 Nedelin-Dmitry
/*
* Программа имеет 2-а режима:
1)Компьютер загадывает число, а пользователь его отгадывает
  Компьютер "загадывает" случайное число, на ввод пользователя реагирует одним из 2-х вариантов:
  1.Пользователь угадал число - программа выводит кол-во попыток игрока и завершается
  2.Пользователь не угадал число - программа подсказывает больше или меньше загаданное число
2)Игрок загадывает число, а компьютер его отгадывает
  Пользователь загадывает число, программа выводит случайное число
  Пользователь отвечает ">", "<", "=":
  1. Пользователь ввёл "<" или ">" - программа меняет диапазон случайного числа
  2. Пользователь ввёл "=" - программа выводит кол-во попыток и завершается 
*/
#include <stdio.h>
#include <locale.h>
#include <time.h>
int main(){
	setlocale(LC_ALL,"Russian");
	int game_mode, divider, random_value, user_input;
	int min = 1, max = 1000, attempt_counter;
	char input_character;
	attempt_counter = 1;
	printf("Кто будет загадывать число?\n1.Комьютер\n2.Вы: ");
	scanf("%d", &game_mode);
	if (game_mode == 1){
		srand(time(NULL));
		random_value = (rand() % 1001 + 1);
		printf("%d",random_value);
		printf("\nПопытайтесь угадать число:");
		while (user_input != random_value){
			scanf("%d", &user_input);
			if (user_input == random_value){
				printf("Вы угадали. Кол-во попыток:%d", attempt_counter);
				break;
			}
			if (user_input > random_value){
	   			attempt_counter += 1;
				printf("Загаданое число меньше");    	  
			}
			if (user_input < random_value){
        		attempt_counter += 1;
				printf("Загаданное число больше");
			}
	    }
	}
	if (game_mode == 2){
		
		printf("Введите число в диапазоне от 1 до 1000: ");
		scanf("%d",&user_input);
		random_value=(rand() % (max - min + 1) + min);
		printf("%d\n",random_value);
		while (1){
			scanf(" %c",&input_character);
			if (input_character == '>'){
				min = random_value;
				random_value = (rand() % (max - min + 1) + min);
				printf("%d\n",random_value);
				attempt_counter += 1;
			}
			if (input_character == '<'){
				max = random_value;
				random_value = (rand() % (max - min + 1) + min);
				printf("%d\n",random_value);
				attempt_counter += 1;
			}
			if (input_character == '='){
			printf("Кол-во попыток:%d", attempt_counter);
			break;
			}
		}	
	}
	return 0;
	
}