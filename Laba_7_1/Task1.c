#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <locale.h>
#define MAX_SIZE 50

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Объявляем двумерный массив, а также количество его строк и столбцов
	int arr[MAX_SIZE][MAX_SIZE];
	int row, col;

	// Вводим количество строк и столбцов и проверяем данные
	puts("Введите количество строк и столбцов матрицы через пробел:");
	while (scanf("%d %d", &row, &col) != 2 || row < 1 || row > MAX_SIZE || col < 1 || col > MAX_SIZE)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так... Повторите ввод:");
	}

	// Заполняем массив и проверяем данные
	for (int i = 0; i < row; i++)
	{
		printf("Введите %d - ю строку:\n", i + 1);
		for (int j = 0; j < col; j++)
		{
			printf("arr[%2d][%2d] = ", i + 1, j + 1);
			while (scanf("%d", &arr[i][j]) != 1)
			{
				while (getchar() != '\n');
				puts("Вы ввели что-то не так... Повторите ввод:");
				printf("arr[%2d][%2d] = ", i + 1, j + 1);
			}
		}
	}

	// Объявляем вспомогательную переменную F
	int F;

	// Вводим F
	puts("Введите число F:");
	while (scanf("%d", &F) != 1)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так... Повторите ввод:");
	}


	// Объявляем переменную произведения и флаг
	int prod = 1, flag = 0;

	// Производим подсчеты
	for (int i = 0; i < row; i += 2)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] <= F)
			{
				prod *= arr[i][j];
				flag++;
			}
		}
	}

	// Проверяем на нахождение значений
	if (flag == 0)
	{
		puts("К сожалению, в вашей матрице нет элементов, удовлетворяющих условию задачи");
	}
	else
	{
		puts("Исходная матрица:");
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				printf("%3d  ", arr[i][j]);
			}
			puts("");
		}
		printf("Произведение элементов матрицы, стоящих на нечетных строках и небОльших числа F (%d): %d\n", F, prod);
	}

	system("pause");
}