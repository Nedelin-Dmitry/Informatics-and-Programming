//Copyright 2021 Nedelin-Dmitry
/*
*Программа вычисляет массу шкафа используя формулу m = p * V
*Где m-масса части шкафа, p-плотность материала этой части, а V - её объём
*/
#include <stdio.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL,"Russian");
	double p_dwp, p_dsp, p_der;// Плотность ДВП,ДСП,Дерева
	double heights, width, depth, thickness_shelf;//h-высота,w-ширина,tpol-толщина полки,d-глубина,m-общая масса
	double mass = 0, thickness_back_wall = 5, thickness_side_wall = 15,
	double thickness_cover = 15, thickness_door = 100, thickness_shelf = 0;
	//t-толщина: z-задней стенки,b-боковой стенки,w-верхняя/нижняя крышки,p-полка
	printf("Введите плотность ДВП,ДСП,дерева(через пробел):");
	scanf("%lf %lf %lf", &p_dwp, &p_dsp, &p_der);
	printf("Для ввода используйте сантиметры,вводите данные через пробел");
	printf("Введите высоту,ширину задней стенки:");
	scanf_s("%lf %lf", &heights, &width);
//Перевожу все значения в метры и по формуле m=p*V=p*a*b*c вычисляю массу предмета добавляя к её к массе шкафа
	heights /= 100;
    width /= 100;
	thickness_back_wall /= 1000;
    double number_shelves = heights / 40; //кол-во полок
	mass = p_dwp * heights * width * thickness_back_wall;
		printf("Введите высоту и глубину  боковой стенки:");
	scanf("%lf %lf", &heights, &depth);
	heights /= 100;
	depth /= 100;
	thickness_side_wall /= 1000;
	mass += (2 * p_dsp * thickness_side_wall * heights * depth);
		printf("Введите ширину и глубину верхней крышки:");
	scanf("%lf %lf", &width, &depth);
	width /= 100;
	depth /= 100;
	thickness_cover /= 1000;
	mass += (2 * p_dsp * width * depth * thickness_cover);
		printf("Введите высоту и ширину двери:");
	scanf("%lf %lf", &heights, &width);
	heights /= 100;
	width /= 100;
	thickness_door /= 1000;
	mass += (2 * p_der * thickness_door * heights * width);
		printf("Введите высоту,ширину(в см),толщину(в мм) полок:");
	scanf("%lf %lf %lf",&heights, &width, &thickness_shelf);
	heights /= 100;
	width /= 100;
	thickness_shelf /= 1000;
	mass = (number_shelves * heights * width * thickness_shelf * p_dsp);
	printf("Масса шкафа в кг:%.3f", mass);
	return 0; 
	
}