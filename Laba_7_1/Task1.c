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

	// ��������� ��������� ������, � ����� ���������� ��� ����� � ��������
	int arr[MAX_SIZE][MAX_SIZE];
	int row, col;

	// ������ ���������� ����� � �������� � ��������� ������
	puts("������� ���������� ����� � �������� ������� ����� ������:");
	while (scanf("%d %d", &row, &col) != 2 || row < 1 || row > MAX_SIZE || col < 1 || col > MAX_SIZE)
	{
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���... ��������� ����:");
	}

	// ��������� ������ � ��������� ������
	for (int i = 0; i < row; i++)
	{
		printf("������� %d - � ������:\n", i + 1);
		for (int j = 0; j < col; j++)
		{
			printf("arr[%2d][%2d] = ", i + 1, j + 1);
			while (scanf("%d", &arr[i][j]) != 1)
			{
				while (getchar() != '\n');
				puts("�� ����� ���-�� �� ���... ��������� ����:");
				printf("arr[%2d][%2d] = ", i + 1, j + 1);
			}
		}
	}

	// ��������� ��������������� ���������� F
	int F;

	// ������ F
	puts("������� ����� F:");
	while (scanf("%d", &F) != 1)
	{
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���... ��������� ����:");
	}


	// ��������� ���������� ������������ � ����
	int prod = 1, flag = 0;

	// ���������� ��������
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

	// ��������� �� ���������� ��������
	if (flag == 0)
	{
		puts("� ���������, � ����� ������� ��� ���������, ��������������� ������� ������");
	}
	else
	{
		puts("�������� �������:");
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				printf("%3d  ", arr[i][j]);
			}
			puts("");
		}
		printf("������������ ��������� �������, ������� �� �������� ������� � ��������� ����� F (%d): %d\n", F, prod);
	}

	system("pause");
}