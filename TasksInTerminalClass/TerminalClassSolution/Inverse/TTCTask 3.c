//Copyright 2021 Nedelin-Dmitry
/*
Программа повторяется пока пользователь не введёт "0" для выхода

Проверка на корректность ввода пользователем
Пользователь выбирает одну из двух функций:
1)Перевернуть число:
Прибавляем последнюю цифру введённого значения к переменной,после чего увеличиваем её разряд и делим "убираем" последнюю цифру
2)Вывести сумму цифр числа:
Прибавлчем к переменной число самого низкого разряда, после чего "убираем" его делением на 10
*/
#include <stdio.h>
int main(){
  int numm, inverse, option;
  int isWork = 1;
  while (isWork){
 	 printf("\nInput number:");
 	 printf("\nfor exit input 0");
 	 int isError = 0;
 	 do {
         if (isError) {
             printf("Wrong input! Try again.");
         }
 		 printf("\nInput positive number:");
 		 scanf("%d", &numm);
 		 if (numm == 0){
 		 	  isWork = 0; 
 			  break;
 		 }
 		 isError = (numm <= 0);
     } while (isError);
 		 while(1){
 		     printf("\n1- invers number\n2- Sum of digits of a number\n");
 		     scanf("%d",&option);
 		     if (option == 1 || option == 2){
                 break;
 		     }
 		     else{
                 printf("Wrong input! Try again");
 		     }
 		 }
 		 if (option == 1){ 
             while(numm){
                 inverse *= 10;
 		         inverse += (numm % 10); 
 		         numm /= 10;
 		     }
 		 }
 		 if (option == 2){
 			 while (numm){
 				 inverse += numm % 10;
 				 numm /= 10;
 			 }
 		 }
 		 if (isWork){
 			 printf("\nResult:%d\n", inverse);
 			 printf("\nInput 0 to EXIT");
 		 }
  }
	return 0;

}