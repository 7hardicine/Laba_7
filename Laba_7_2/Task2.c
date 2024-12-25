#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>

// Вариант 10.
// Использовать динамический массив
// Заменить в матрице элементы предпоследней строки на минимальные элементы соответствующих столбцов.

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int row, col;
	
	puts("Введите количество строк и столбцов матрицы:");
	while (scanf_s("%d %d", &row, &col) != 2 || row < 2 || col < 2)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так... Возможно ваша матрица является одномерным массивом :)\nПовторите ввод:");
	}

	int* arr = (int*)malloc(row * col * sizeof(int));

	if (arr == NULL)
	{
		puts("Нет свободной памяти");
		return;
	}

	puts("Введите элементы матрицы:");

	for (int i = 0; i < row; i++)
	{
		printf_s("Введите %d - ю строку матрицы:\n", i + 1);
		for (int j = 0; j < col; j++)
		{
			printf_s("arr[%2d][%2d] = ", i + 1, j + 1);
			while (scanf_s("%d", arr + i * col + j) != 1)
			{
				while (getchar() != '\n');
				puts("Вы ввели что-то не так... Повторите ввод:");
				printf_s("arr[%2d][%2d] = ", i + 1, j + 1);
			}
		}
	}

	puts("Исходная матрица:");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf_s("%3d ", *(arr + i * col + j));
		}
		puts("");
	}

	int pre_last = row - 2;
	int min;

	for (int j = 0; j < col; j++)
	{
		min = *(arr + pre_last * col + j);
		for (int i = 0; i < row; i++)
		{
			if (*(arr + i * col + j) < min)
			{
				min = *(arr + i * col + j);
			}
		}
		*(arr + pre_last * col + j) = min;
	}

	puts("Преобразованная матрица:");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf_s("%3d ", *(arr + i * col + j));
		}
		puts("");
	}

	free(arr);

	system("pause");
}