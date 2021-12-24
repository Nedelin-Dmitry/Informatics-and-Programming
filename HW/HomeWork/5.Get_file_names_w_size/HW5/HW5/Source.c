//Copyright 2021 Nedelin-Dmitry
/*
Разработать прототип файлового менеджера с функцией показа файлов в заданном каталоге, упорядоченных по возрастанию/убыванию размера.

Входные данные:

Путь до директории, в которой необходимо отсортировать содержимое.
Метод сортировки.
Выходные данные:

Отсортированный список имен файлов с указанием размера.
Время сортировки.
Программа должна предоставлять пользователю возможность сменить метод сортировки и повторно формировать выходные данные. Программа должна реализовывать диалог с пользователем посредством интерфейса, который включает:

возможность ввода пути до заданного каталога;
возможность выбора метода сортировки;
возможность просмотра отсортированного списка файлов с указанием размера.
Полный список методов сортировки задается отдельно. Методы, которые должен будет реализовать каждый студент также определяются отдельно.
*/

#define _CRT_SECURE_NO_WARNINGS
#define size 8

#include <stdio.h>
#include <"C:/Users/Admin/Desktop/Studies/Prog/dirent-master/include/dirent.h">
#include <sys/stat.h>
#include <string.h>
#include <malloc.h>
char mass_name[size][200], mass_name_save[size][200];
int mass_size[size], mass_size_save[size], pos = 0;
//Рабочая папка:
// /storage/emulated/0/Z_Anime/4_HW5
/// <summary>
/// функция, возвращающая размер файла
/// </summary>
/// <param name="file">полный или относительный путь до файла</param>
/// <returns>размер файла</returns>
int getFileSize(const char* file)
{
	struct stat st;
	int full_size = 0;

	if (stat(file, &st) == 0)
	{
		// если это папка
		if ((st.st_mode & S_IFMT) == S_IFDIR)
			return -1;
		// если обычный файл
		else if ((st.st_mode & S_IFMT) == S_IFREG)
			return st.st_size;
		// если что-то иное (сокет, FIFO (именованный канал) и др.)
		else
			return -2;
	}
}

/// <summary>
/// функция, печатающая названия файлов и размеры в каталоге и внутренних подкаталогов
/// </summary>
/// <param name="path">путь до каталога</param>
void getSizesFromDir(char* path)
{
	struct dirent* cur_file;
	DIR* dir;

	char full_file_path[200];

	// открываем рабочую директорию
	dir = opendir(path);

	// если удалось открыть директорию
	if (dir)
	{
		// считываем файлы внутри директории в переменную cur_file, пока файлы не кончатся
		while ((cur_file = readdir(dir)) != NULL)
		{
			// игнорируем системные папки ./ и ../
			// если попались записи, начинающиеся на . или .. - пропускаем их
			if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name))
			{
				// копируем путь в новую переменную, вставляем символ разделителя директории,
				// добавляем имя элемента (файла или папки)
				strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
				// получаем размер или -1, если это не файл, а вложенная папка
				int cur_file_size = getFileSize(full_file_path);
				if (cur_file_size >= 0)
				{
					// для файла печатаем его имя и размер
					printf("%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
					mass_size[pos] = cur_file_size;
					strcpy(mass_name[pos], cur_file->d_name);
					pos += 1;
				}
				else if (cur_file_size == -1)
					// для вложенной папки вызываем РЕКУРСИВНО написанный метод
					getSizesFromDir(full_file_path);
			}
		}
		// не забываем закрыть директорию
		closedir(dir);
	}
}

float sort_select(int array_int[size], char array_cr[size][200])
{
	clock_t started = clock();
	char char_save[200];
	//Выбираем позицию в массиве
	for (int i = 0; i < size - 1; i++)
	{
		int min_i = i;
		//Ищем наименьшее число для этой позиции
		for (int j = i + 1; j < size; j++)
		{
			if (array_int[j] < array_int[min_i])
			{
				min_i = j;
			}
		}
		//Меняем местами
		int save_int = array_int[i];
		array_int[i] = array_int[min_i];
		array_int[min_i] = save_int;
		strcpy(char_save, array_cr[i]);
		strcpy(array_cr[i], array_cr[min_i]);
		strcpy(array_cr[min_i], char_save);
	}
	clock_t end = clock();
	return end - started;
}

float sort_merge(int array_int[size], char array_cr[size][200])
{
	clock_t started_2 = clock();
	char char_save[200];
	int mid = size / 2; // середина массива
	if (size % 2 == 1)
		mid += 1;
	int h = 1; // шаг
	int* c = (int*)malloc(size * sizeof(int));
	int step;
	while (h < size)
	{
		step = h;
		int i = 0;	 // индекс первого пути
		int j = mid; // индекс второго пути
		int k = 0;	 // индекс элемента в результирующей последовательности
		while (step <= mid)
		{
			while ((i < step) && (j < size) && (j < (mid + step)))
			{ // пока не дошли до конца пути
				// заполняем следующий элемент формируемой последовательности
				// меньшим из двух просматриваемых
				if (array_int[i] < array_int[j])
				{
					c[k] = array_int[i];
					strcpy(char_save, array_cr[k]);
					strcpy(array_cr[k], array_cr[i]);
					strcpy(array_cr[i], char_save);
					i++;
					k++;
				}
				else
				{
					c[k] = array_int[j];
					strcpy(char_save, array_cr[k]);
					strcpy(array_cr[k], array_cr[j]);
					strcpy(array_cr[j], char_save);
					j++;
					k++;
				}
			}
			while (i < step)
			{ // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
				c[k] = array_int[i];
				strcpy(char_save, array_cr[k]);
				strcpy(array_cr[k], array_cr[i]);
				strcpy(array_cr[i], char_save);
				i++;
				k++;
			}
			while ((j < (mid + step)) && (j < size))
			{ // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
				c[k] = array_int[j];
				strcpy(char_save, array_cr[k]);
				strcpy(array_cr[k], array_cr[j]);
				strcpy(array_cr[j], char_save);
				j++;
				k++;
			}
			step = step + h; // переходим к следующему этапу
		}
		h = h * 2;
		// Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
		for (i = 0; i < size; i++)
			array_int[i] = c[i];
	}
	clock_t end_2 = clock();
	return end_2 - started_2;
}

float sort_count(int array_int[], char array_cr[size][200])
{
	clock_t started = clock();
	int max = -1;
	int min = 999999;
	char char_save[200];
	//находим миксимальный и минимальный элементы массива
	for (int i = 0; i < size; i++)
	{
		if (array_int[i] > max)
		{
			max = array_int[i];
		}
		if (array_int[i] < min)
		{
			min = array_int[i];
		}
	}
	int del = 10;
	while (min / del > 100)
	{
		del *= 10;
	}
	//Создаём массив длиной от 1 до max + 1
	//сравниваем номер элемента массива с значением, в случае совпадения + 1
	int add_mass[1001];
	for (int i = 0; i < 1001; i++)
	{
		add_mass[i] = 0;
	}
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == array_int[j] / del)
			{
				add_mass[i] = 1;
			}
		}
	}

	//записываем в массив в порядке возрастания
	int j = 0;
	for (int i = 0; i < 1001; i++)
	{
		if (add_mass[i] > 0)
		{
			for (int k = 0; k < size; k++)
			{
				if (array_int[k] / 100 == i || array_int[k] / 1000 == i)
				{
					int save;
					save = array_int[j];
					array_int[j] = array_int[k];
					array_int[k] = save;
					strcpy(char_save, array_cr[j]);
					strcpy(array_cr[j], array_cr[k]);
					strcpy(array_cr[k], char_save);
					j++;
				}
			}
		}
	}
	clock_t end = clock();
	return end - started;
}

int main()
{
	char path[200];
	// считываем путь (по сути scanf_s для строки)
	printf("Input path to dir:\n");
	gets(path);
	getSizesFromDir(path);
	for (int i = 0; i < size; i++)
	{
		mass_size_save[i] = mass_size[i];
		for (int j = 0; j < 200; j++) {
			mass_name_save[i][j] = mass_name[i][j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("\n");
		for (int j = 0; j < 200; j++)
		{
			printf("%c", mass_name[i][j]);
		}
	}

	int mode;
	printf("Выберите вид сортировки:\n1.Сортировка выбором\n2.Сортировка слиянием\n3.Сортировка подсчётом\n4.Вернуть изначальный порядок\n");
	while (1)
	{
		scanf("%d", &mode);
		if (mode == 1 || mode == 2 || mode == 3 || mode == 4 || mode == 0)
			break;
		printf("\nНеправильный ввод, попробуйте снова\n");
	}
	if (mode == 1)
	{
		printf("\nСортировка выбором\n");
		float time = sort_select(mass_size, mass_name);
		printf("Время выполнения:%f", time);
		for (int i = 0; i < size; i++)
		{
			printf("\n");
			for (int j = 0; j < 200; j++)
			{
				printf("%c", mass_name[i][j]);
			}
			printf(" - %d B, %d (kB) ", mass_size[i], mass_size[i] / 1024);
		}
	}
	if (mode == 2)
	{
		printf("\nСортировка Слиянием\n");
		float time = sort_merge(mass_size, mass_name);
		printf("Время выполнения:%f", time);
		for (int i = 0; i < size; i++)
		{
			printf("\n");
			for (int j = 0; j < 200; j++)
			{
				printf("%c", mass_name[i][j]);
			}
			printf(" - %d B, %d (kB) ", mass_size[i], mass_size[i] / 1024);
		}
	}

	if (mode == 3)
	{
		printf("\nСортировка подсчётом\n");
		float time = sort_merge(mass_size, mass_name);
		printf("Время выполнения:%f", time);
		for (int i = 0; i < size; i++)
		{
			printf("\n");
			for (int j = 0; j < 200; j++)
			{
				printf("%c", mass_name[i][j]);
			}
			printf(" - %d B, %d (kB) ", mass_size[i], mass_size[i] / 1024);
		}
	}
	if (mode == 4) {
		for (int i = 0; i < size; i++)
		{
			printf("\n");
			for (int j = 0; j < 200; j++)
			{
				printf("%c", mass_name_save[i][j]);
			}
			printf(" - %d B, %d (kB) ", mass_size_save[i], mass_size_save[i] / 1024);
		}
	}
	///storage/emulated/0/Z_Anime/4_HW5
	/*
Сортировка выбором
Берём первый элемент(i ++)
ищем минимальное среди остальных
меняем
Just for it
Сортировка слиянием
описал в самой функции
Сортировка подсчётом
Создаётся побочный массив размером от минимального до максимального,где каждый элемент - это счётчик


*/

	return 0;
}
