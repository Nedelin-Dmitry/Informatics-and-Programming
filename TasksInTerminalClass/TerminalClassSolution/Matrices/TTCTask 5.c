// Copyright 2021 Nedelin-Dmitry
/*
Постановка задачи.

Реализована некоторая программа, работающая с матричными операциями.

Программист начал работать над ней и понял, что в ней много дублирования кода.

Он посмотрел свой код и не увидел проблем в самом коде. Чтобы исправить

проблему дублирования он решил вынести часть кода в функции.

Помогите ему в этом, а также допишите функционал, который он не успел.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2
#define V 1
int generateRandNumber(int maximum, int minimum) {

    int value = (maximum - minimum) * ((float)rand() / RAND_MAX) + minimum;
    return value;

}

int** setMemory(int** matrix, int n, int m) {
  matrix = (int**)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++)
    matrix[i] = (int*)malloc(m * sizeof(int));
  return matrix;
}
int main() {

    int** matrix_A = NULL, ** matrix_B = NULL, ** result = NULL, **matrix_C = NULL, **matrix_D = NULL, **matrix_E = NULL, ** matrix_F = NULL, ** matrix_G = NULL, ** matrix_H = NULL, **matrix_K = NULL, **result_2 = NULL;
    int max = 4, min = 0, value = 0, value_2 = 0;
    // выделение памяти под матрицу (двумерный массив)
 // N строк, M столбцов (матрица N x M)
    matrix_A = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_A[i] = (int*)malloc(M * sizeof(int));
    // заполнение массива рандомными значениями
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix_A[i][j] = generateRandNumber(max, min);
        }
    }
    printf("Matrix A =\n");
    // печать матрицы на экран
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix_A[i][j]);
        }
        printf("\n");
    }
    // умножение матрицы на число
    value = (max - min) * ((float)rand() / RAND_MAX) + min;
    // выделение памяти
    result = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        result[i] = (int*)malloc(M * sizeof(int));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result[i][j] = matrix_A[i][j] * value;
        }
    }
    printf("Matrix A x %d =\n", value);
    // печать матрицы на экран
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    // транспонирование матрицы
    result = (int**)malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        result[i] = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix_A[j][i];
        }
    }
    printf("Matrix AT =\n");
    // печать матрицы на экран
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    // очищение результата после вывода
    for (int i = 0; i < M; i++) free(result[i]);
    free(result);
    // умножение двух матриц
    matrix_B = (int**)malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        matrix_B[i] = (int*)malloc(K * sizeof(int));
    // заполнение массива рандомными значениями
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            matrix_B[i][j] = generateRandNumber(max, min);
        }
    }
    printf("Matrix B =\n");
    // печать матрицы на экран
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", matrix_B[i][j]);
        }
        printf("\n");
    }
    result = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        result[i] = (int*)malloc(K * sizeof(int));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            result[i][j] = 0;
            for (int k = 0; k < M; k++) {
                result[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
    printf("Matrix AxB =\n");
    // печать матрицы на экран
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    // очищение результата после вывода
    for (int i = 0; i < N; i++) free(result[i]);
    free(result);
    // сложение двух матриц

    // Выделения памяти под матрицу C и D
    matrix_C = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_C[i] = (int*)malloc(M * sizeof(int));
        matrix_D = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_D[i] = (int*)malloc(M * sizeof(int));
     // заполнение массива C рандомными значениями
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix_C[i][j] = generateRandNumber(max, min);
        }
    }
    
    printf("Матрица C\n");
    // печать матрицы на экран
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix_C[i][j]);
        }
        printf("\n");
    }
	for(int i = 0 ; i < N; i++){
	   for(int j = 0; j < M; j++){
	   	matrix_D[i][j] = matrix_A[i][j] + matrix_C[i][j];
	   }
	}
	// печать матрицы
	printf("Матрица A+C\n");
	for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix_D[i][j]);
        }
        printf("\n");
    }
	
    // умножение вектора на число

    //Выделение памяти на матрицу-вектор E
    matrix_E = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_E[i] = (int*)malloc(V * sizeof(int));
	//Заполнение массива-вектора E рандомными значениями
	  for (int i = 0; i < N; i++) {
        for (int j = 0; j < V; j++) {
            matrix_E[i][j] = generateRandNumber(max, min);
        }
    }
	//Вывод матрицы-вектора E и E * value_2
	printf("Матрица-вектор E\n");
	for (int i = 0; i < N; i++){
        for (int j = 0; j < V; j++) {
            printf("%d ", matrix_E[i][j]);
        }
        printf("\n");
    }
    printf("E*4=\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < V; j++) {
            printf("%d\n", matrix_E[i][j] * 4);
        }
    }
    // сложение двух векторов
//Выделение памяти на матрицу-вектор F и матрицу-вектор G(E+F)
    matrix_F = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_F[i] = (int*)malloc(V * sizeof(int));
    matrix_G = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_G[i] = (int*)malloc(V * sizeof(int));
    //Заполнение массива-вектора E рандомными значениями
	  for (int i = 0; i < N; i++) {
        for (int j = 0; j < V; j++) {
            matrix_F[i][j] = generateRandNumber(max, min);
        }
    }
    //Вывод матрицы-вектора F
	printf("Матрица-вектор F\n");
	for (int i = 0; i < N; i++){
        for (int j = 0; j < V; j++) {
            printf("%d ", matrix_F[i][j]);
        }
        printf("\n");
    }
    // Сложение E + F
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < V; j++) {
            matrix_G[i][j] = matrix_E[i][j] + matrix_F[i][j];
        }
    }
    //Вывод E + F
    	printf("Матрица-вектор E + F\n");
	for (int i = 0; i < N; i++){
        for (int j = 0; j < V; j++) {
            printf("%d ", matrix_G[i][j]);
        }
        printf("\n");
    }
    // умножение двух векторов
//Выделение памяти на матрицу-вектор H и матрицу K
    matrix_H = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++)
        matrix_H[i] = (int*)malloc(N * sizeof(int));
    matrix_K = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_K[i] = (int*)malloc(N * sizeof(int));
         //Заполнение массива-вектора H рандомными значениями
	  for (int i = 0; i < V; i++) {
        for (int j = 0; j < N; j++) {
            matrix_H[i][j] = generateRandNumber(max, min);
        }
    }
    //Вывод матрицы H
    	printf("Матрица-вектор H\n");
	for (int i = 0; i < V; i++){
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix_H[i][j]);
        }
        printf("\n");
    }
     result_2 = (int**)malloc(N * sizeof(int*));
     //Умножения F на H
    for (int i = 0; i < N; i++)
        result_2[i] = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result_2[i][j] = 0;
            for (int k = 0; k < V; k++) {
                result_2[i][j] += matrix_F[i][k] * matrix_H[k][j];
            }
        }
    }
        printf("Матрица F*H =\n");
    // печать матрицы на экран
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result_2[i][j]);
        }
        printf("\n");
    }

      // очищение всей выделенной памяти

    for (int i = 0; i < N; i++) free(matrix_A[i]);
    free(matrix_A);
    for (int i = 0; i < M; i++) free(matrix_B[i]);
    free(matrix_B);
    for (int i = 0; i < N; i++) free(matrix_C[i]);
    free(matrix_C);
    for (int i = 0; i < N; i++) free(matrix_D[i]);
    free(matrix_D);
    for (int i = 0; i < V; i++) free(matrix_F[i]);
    free(matrix_F);
    for (int i = 0; i < V; i++) free(matrix_G[i]);
    free(matrix_G);
    for (int i = 0; i < V; i++) free(matrix_H[i]);
    free(matrix_H);
    for (int i = 0; i < N; i++) free(matrix_K[i]);
    free(matrix_K);
    for (int i = 0; i < N; i++) free(result_2[i]);
    free(result_2);
    
    
    return 0;

}

