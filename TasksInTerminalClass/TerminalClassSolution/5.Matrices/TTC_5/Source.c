// Copyright 2021 Nedelin-Dmitry
/*
Постановка задачи.

Реализована некоторая программа, работающая с матричными операциями.

Программист начал работать над ней и понял, что в ней много дублирования кода.

Он посмотрел свой код и не увидел проблем в самом коде. Чтобы исправить

проблему дублирования он решил вынести часть кода в функции.

Помогите ему в этом, а также допишите функционал, который он не успел.

*/
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 4
#define M 3
#define K 2
int generateRandNumber(int maximum, int minimum) {

    int value = (maximum - minimum) * ((float)rand() / RAND_MAX) + minimum;
    return value;
}
void show_arr(int array[], int sz_arr) {
    for (int i = 0; i < sz_arr; i++) {
        printf("%d ", array[i]);
    }
}
void show_arr_2(int* array[], int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
void full_up_2(int* array[], int a, int b, int mx, int mn) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            array[i][j] = generateRandNumber(mx, mn);
        }
    }
}
void full_up(int array[], int a, int mx, int mn) {
    for (int i = 0; i < a; i++) {
        array[i] = generateRandNumber(mx, mn);
    }
}
int** set_memory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
}

int main() {

    int** matrix_A = NULL, ** matrix_B = NULL, ** result = NULL, ** matrix_C = NULL, ** matrix_D = NULL, * vector_E = NULL, * vector_F = NULL, * vector_G = NULL, * vector_H = NULL, * vector_K = NULL;
    float result_2 = 0;
    int max = 4, min = 0, value = 0, value_2 = 0;
    // выделение памяти под матрицу (двумерный массив)
 // N строк, M столбцов (матрица N x M)
    matrix_A = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_A[i] = (int*)malloc(M * sizeof(int));
    // заполнение массива рандомными значениями
    full_up_2(matrix_A, 4, 3, max, min);
    printf("Matrix A =\n");
    // печать матрицы на экран
    show_arr_2(matrix_A, 4, 3);
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
    show_arr_2(result, 4, 3);
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
    show_arr_2(result, 3, 4);
    // очищение результата после вывода
    for (int i = 0; i < M; i++) free(result[i]);
    free(result);
    // умножение двух матриц
    matrix_B = (int**)malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        matrix_B[i] = (int*)malloc(K * sizeof(int));
    // заполнение массива рандомными значениями
    full_up_2(matrix_B, 3, 2, max, min);
    printf("Matrix B =\n");
    // печать матрицы на экран
    show_arr_2(matrix_B, 3, 2);
    // A x B
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
    show_arr_2(result, 4, 2);
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
    full_up_2(matrix_C, 4, 3, max, min);
    printf("Matrix C\n");
    // печать матрицы на экран
    show_arr_2(matrix_C, 4, 3);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix_D[i][j] = matrix_A[i][j] + matrix_C[i][j];
        }
    }
    // печать матрицы
    printf("Matrix A+C\n");
    show_arr_2(matrix_D, 4, 3);

    // умножение вектора на число

    //Выделение памяти на вектор E
    vector_E = (int*)malloc(K * sizeof(int));
    //Заполнение массива-вектора E рандомными значениями
    full_up(vector_E, 2, max, min);
    //Вывод матрицы-вектора E и E * value_2
    printf("Matrix-vector E\n");
    show_arr(vector_E, 2);
    printf("\nE*4=\n");
    for (int i = 0; i < K; i++) {
        printf("%d ", vector_E[i] * 4);
    }
    printf("\n");
    // сложение двух векторов
//Выделение памяти на матрицу-вектор F и матрицу-вектор G(E+F)
    vector_F = (int*)malloc(K * sizeof(int));
    vector_G = (int*)malloc(K * sizeof(int));
    //Заполнение массива-вектора E рандомными значениями
    full_up(vector_F, 2, max, min);
    //Вывод матрицы-вектора F
    printf("Matrix-vector F\n");
    show_arr(vector_F, 2);
    printf("\n");
    // Сложение E + F
    for (int i = 0; i < K; i++) {
        vector_G[i] = vector_E[i] + vector_F[i];
    }
    //Вывод E + F
    printf("Matrix-vector E + F\n");
    show_arr(vector_G, 2);
    printf("\n");
    // умножение двух векторов
//Выделение памяти на матрицу-вектор H и матрицу K
    vector_H = (int*)malloc(K * sizeof(int));
    vector_K = (int*)malloc(K * sizeof(int));
    //Заполнение массивов-векторов H и K рандомными значениями
    full_up(vector_H, 2, max, min);
    full_up(vector_K, 2, max, min);
    //Вывод матрицы H
    printf("Matrix-vector H\n");
    show_arr(vector_H, 2);
    //Умножения F на H
    float long_H, long_K;
    int degress = 1;
    int i = 0;
    long_H = sqrt((vector_H[i] * vector_H[i]) + (vector_H[i + 1] * vector_H[i + 1]));
    long_K = sqrt((vector_K[i] * vector_K[i]) + (vector_K[i + 1] * vector_K[i + 1]));
    result_2 = long_H * long_K * sin(M_PI_2);
    printf("\nProduct of vectors F*H =\n");
    printf("\nH %.2f", long_H);
    printf("\nK %.2f", long_K);
    printf("\nD %d", degress);
    // печать ответа на экран
    printf("%.2f", result_2);


    // очищение всей выделенной памяти

    for (int i = 0; i < N; i++) free(matrix_A[i]);
    free(matrix_A);
    for (int i = 0; i < M; i++) free(matrix_B[i]);
    free(matrix_B);
    for (int i = 0; i < N; i++) free(matrix_C[i]);
    free(matrix_C);
    for (int i = 0; i < N; i++) free(matrix_D[i]);
    free(matrix_D);
    free(vector_F);
    free(vector_G);
    free(vector_H);
    free(vector_K);

    return 0;

}

