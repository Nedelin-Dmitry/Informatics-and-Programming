//Copyright 2021 Nedelin-Dmitry
/*
����������� �������� ��������� ��������� � �������� ������ ������ � �������� ��������, ������������� �� �����������/�������� �������.

������� ������:

���� �� ����������, � ������� ���������� ������������� ����������.
����� ����������.
�������� ������:

��������������� ������ ���� ������ � ��������� �������.
����� ����������.
��������� ������ ������������� ������������ ����������� ������� ����� ���������� � �������� ����������� �������� ������. ��������� ������ ������������� ������ � ������������� ����������� ����������, ������� ��������:

����������� ����� ���� �� ��������� ��������;
����������� ������ ������ ����������;
����������� ��������� ���������������� ������ ������ � ��������� �������.
������ ������ ������� ���������� �������� ��������. ������, ������� ������ ����� ����������� ������ ������� ����� ������������ ��������.
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
//������� �����:
// /storage/emulated/0/Z_Anime/4_HW5
/// <summary>
/// �������, ������������ ������ �����
/// </summary>
/// <param name="file">������ ��� ������������� ���� �� �����</param>
/// <returns>������ �����</returns>
int getFileSize(const char* file)
{
	struct stat st;
	int full_size = 0;

	if (stat(file, &st) == 0)
	{
		// ���� ��� �����
		if ((st.st_mode & S_IFMT) == S_IFDIR)
			return -1;
		// ���� ������� ����
		else if ((st.st_mode & S_IFMT) == S_IFREG)
			return st.st_size;
		// ���� ���-�� ���� (�����, FIFO (����������� �����) � ��.)
		else
			return -2;
	}
}

/// <summary>
/// �������, ���������� �������� ������ � ������� � �������� � ���������� ������������
/// </summary>
/// <param name="path">���� �� ��������</param>
void getSizesFromDir(char* path)
{
	struct dirent* cur_file;
	DIR* dir;

	char full_file_path[200];

	// ��������� ������� ����������
	dir = opendir(path);

	// ���� ������� ������� ����������
	if (dir)
	{
		// ��������� ����� ������ ���������� � ���������� cur_file, ���� ����� �� ��������
		while ((cur_file = readdir(dir)) != NULL)
		{
			// ���������� ��������� ����� ./ � ../
			// ���� �������� ������, ������������ �� . ��� .. - ���������� ��
			if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name))
			{
				// �������� ���� � ����� ����������, ��������� ������ ����������� ����������,
				// ��������� ��� �������� (����� ��� �����)
				strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
				// �������� ������ ��� -1, ���� ��� �� ����, � ��������� �����
				int cur_file_size = getFileSize(full_file_path);
				if (cur_file_size >= 0)
				{
					// ��� ����� �������� ��� ��� � ������
					printf("%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
					mass_size[pos] = cur_file_size;
					strcpy(mass_name[pos], cur_file->d_name);
					pos += 1;
				}
				else if (cur_file_size == -1)
					// ��� ��������� ����� �������� ���������� ���������� �����
					getSizesFromDir(full_file_path);
			}
		}
		// �� �������� ������� ����������
		closedir(dir);
	}
}

float sort_select(int array_int[size], char array_cr[size][200])
{
	clock_t started = clock();
	char char_save[200];
	//�������� ������� � �������
	for (int i = 0; i < size - 1; i++)
	{
		int min_i = i;
		//���� ���������� ����� ��� ���� �������
		for (int j = i + 1; j < size; j++)
		{
			if (array_int[j] < array_int[min_i])
			{
				min_i = j;
			}
		}
		//������ �������
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
	int mid = size / 2; // �������� �������
	if (size % 2 == 1)
		mid += 1;
	int h = 1; // ���
	int* c = (int*)malloc(size * sizeof(int));
	int step;
	while (h < size)
	{
		step = h;
		int i = 0;	 // ������ ������� ����
		int j = mid; // ������ ������� ����
		int k = 0;	 // ������ �������� � �������������� ������������������
		while (step <= mid)
		{
			while ((i < step) && (j < size) && (j < (mid + step)))
			{ // ���� �� ����� �� ����� ����
				// ��������� ��������� ������� ����������� ������������������
				// ������� �� ���� ���������������
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
			{ // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
				c[k] = array_int[i];
				strcpy(char_save, array_cr[k]);
				strcpy(array_cr[k], array_cr[i]);
				strcpy(array_cr[i], char_save);
				i++;
				k++;
			}
			while ((j < (mid + step)) && (j < size))
			{ // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
				c[k] = array_int[j];
				strcpy(char_save, array_cr[k]);
				strcpy(array_cr[k], array_cr[j]);
				strcpy(array_cr[j], char_save);
				j++;
				k++;
			}
			step = step + h; // ��������� � ���������� �����
		}
		h = h * 2;
		// ��������� ������������� ������������������ (������������� �������) � �������� ������
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
	//������� ������������ � ����������� �������� �������
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
	//������ ������ ������ �� 1 �� max + 1
	//���������� ����� �������� ������� � ���������, � ������ ���������� + 1
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

	//���������� � ������ � ������� �����������
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
	// ��������� ���� (�� ���� scanf_s ��� ������)
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
	printf("�������� ��� ����������:\n1.���������� �������\n2.���������� ��������\n3.���������� ���������\n4.������� ����������� �������\n");
	while (1)
	{
		scanf("%d", &mode);
		if (mode == 1 || mode == 2 || mode == 3 || mode == 4 || mode == 0)
			break;
		printf("\n������������ ����, ���������� �����\n");
	}
	if (mode == 1)
	{
		printf("\n���������� �������\n");
		float time = sort_select(mass_size, mass_name);
		printf("����� ����������:%f", time);
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
		printf("\n���������� ��������\n");
		float time = sort_merge(mass_size, mass_name);
		printf("����� ����������:%f", time);
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
		printf("\n���������� ���������\n");
		float time = sort_merge(mass_size, mass_name);
		printf("����� ����������:%f", time);
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
���������� �������
���� ������ �������(i ++)
���� ����������� ����� ���������
������
Just for it
���������� ��������
������ � ����� �������
���������� ���������
�������� �������� ������ �������� �� ������������ �� �������������,��� ������ ������� - ��� �������


*/

	return 0;
}
