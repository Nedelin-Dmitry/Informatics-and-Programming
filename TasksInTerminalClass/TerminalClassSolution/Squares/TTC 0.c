//Copyright 2021 Nedelin-Dmitry
/*
* Программа считает площадь одной из трёх фигур:
* 1.Треугольник
* 2.Прямоугольник
* 3.Окружность
*/
#include<stdio.h>
#include<math.h>
int main(){
	int selection_number;
	double square, side_1, height, side_2, radius;
	printf("Select function:");
	printf("\n 1.triangle square\n 2.restangle square\n 3.circle square\n");
	scanf(" %d", &selection_number);
	if (selection_number == 1){
		printf("\n Input height and base (spase):\n");
		scanf("%lf %lf", &side_1, &height);
		square = 0.5 * side_1 * height;
		printf("Square triangle:a=%.2f", square);
	}
	if (selection_number == 2){
		printf("\nInput two sides square(spase):\n");
		scanf("%lf %lf", &side_1, &side_2);
		square = side_1 * side_2;
		printf("\nSquare rectangle:a=%.2f", square);
	}
	if(selection_number == 3){
		printf("\nInput radius(spase):\n");
		scanf("%lf", &radius);
		square = M_PI * radius * radius;
		printf("\n Square circle:a=%.3f",square);
	}
	return 0;
	
}