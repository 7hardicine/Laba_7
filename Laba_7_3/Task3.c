#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
#define MIN -20
#define MAX 20

// Вариант 10.
// Использовать статический / динамический массив
// Вычислить сумму модулей отрицательных элементов матрицы, расположенных ниже и на главной диагонали.

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int row_col;

	puts("Введите размерность квадратной матрицы m x m (одно значение):");
	while (scanf_s("%d", &row_col) != 1 || row_col < 2)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так... Возможно ваша матрица является одномерным массивом 1 x 1 :)\nПовторите ввод:");
	}

	int* arr = (int*)malloc(row_col * row_col * sizeof(int));

	if (arr == NULL)
	{
		puts("Нет свободной памяти");
		return;
	}

	puts("Исходная матрица:");

	for (int i = 0; i < row_col; i++)
	{
		for (int j = 0; j < row_col; j++)
		{
			*(arr + i * row_col + j) = rand() % (MAX - MIN + 1) + MIN;
			printf_s("%3d ", *(arr + i * row_col + j));
		}
		puts("");
	}

	int summ = 0;

	for (int j = 0; j < row_col; j++)
	{
		for (int i = j; i < row_col; i++)
		{
			if (*(arr + i * row_col + j) < 0)
			{
				summ += abs(*(arr + i * row_col + j));
			}
		}
	}

	printf_s("Сумма модулей отрицательных элементов матрицы, расположенных ниже и на главной диагонали: %d\n", summ);

	free(arr);

	system("pause");
}