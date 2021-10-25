//Copyright 2021 Nedelin-Dmitry
/* Перевернуть массив
пример:
(1,2,3,4,5,6,7,8)->(5,6,7,8,1,2,3,4)
Реализовать 2-мя способами
	1.с доп. массивом
	2. без доп. массива
	1)заполняем первую половину 3-его массива второй половиной 2-го
Потом заполняем вторую половину 3-его массива  первой половиной 2-го
	2)сохраняем 1-е значение,меняем 1-е на второе,второе на созраненное первое
*/
#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL,"rus");
	srand(time(NULL));
	int *mass_1, *mass_2, *mass_3, save, size;
    // первые 3 массива, переменная для сохранения значения
	int max = 9, min = 1, i ; 
	// max и min для рандома
	int p = 0; // для корректоного заполнения 3-го массива
	printf("Введите размер массива(чётное число): ");
	scanf("%d", &size);
	mass_1 = (int*) malloc(size * sizeof(int));
	mass_2 = (int*) malloc(size * sizeof(int));
	mass_3 = (int*) malloc(size * sizeof(int) );
	printf("Без массива:\n");
	for(i = 0;i < size; i++){
		mass_1[i] = i + 1;
		mass_2[i] = mass_1[i];
	}
	//Без массива
	for(i = 0; i < size; i++){
		printf("%d ", mass_1[i]);
	}
	for (i = 0; i < (size / 2); i++){
		save = mass_1[i];
		mass_1[i] = mass_1[size / 2 + i];
		mass_1[size / 2 + i] = save;	
	}
	printf("\n");
	for(i = 0; i < size; i++){
		printf("%d ", mass_1[i]);
	}
	//С дополнительным массивом
	printf("\nРешение с доп. массивом:\n");
	for (i = 0; i < size; i++){
		printf("%d ", mass_2[i]);
	}
	for(i = (size / 2); i < size; i++){
		mass_3[p] = mass_2[i];
		p += 1;
	}
	for (i = 0; i < (size / 2); i++){
		mass_3[p] = mass_2[i];
		p+=1;
	}
	printf("\n");
	for(i = 0;i < size; i++){
		printf("%d ",mass_3[i]);
	}
return 0;
	
}