//Copyright 2021 Nedelin-Dmitry
//На вход подаётся цена за услугу, программа подсчитывает минимальное кол-во монет которое можно отдать за услугу и выводит его
#include <stdio.h>
#include <locale.h>
int main(){
	int price, coins;
	setlocale(LC_ALL,"Russian");
	printf("Ведьмак возьмёт за заказ:");
	scanf("%d", &price);
	while((price / 25) >= 1){
 		price -= 25;
 		coins += 1;
	}
	while((price / 10) >= 1){
 		price -= 10;
 		coins += 1;
	}
	while((price / 5) >= 1){
		price -= 5;
 		c+=1;
	}
	while(price >= 1){
		price -= 1;
		coins += 1;
	}
	printf("Всего потрачено монет: %d", coins);
	return 0;

}