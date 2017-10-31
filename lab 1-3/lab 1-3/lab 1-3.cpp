/*Талалай Данила Андреевич
КТбо 1-8
Вариант 3
Написать программу, которая выводит количество ненулевых элементов массива.
Массив и его длина вводятся пользователем.
*/
#include <stdio.h>
#include <cstdlib> 
#include <windows.h> 
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int *A, check, N, i, count = 0;
	printf("Введите размер массива > "); 
	scanf_s("%d", &N);
		A = new int[N];
		printf("Ввод массива\n"); 
		for (i = 0; i < N; i++) 
		{
			printf("Введите A[%d]> ", i); 
			check = scanf_s("%d", &A[i]);
			if (!check)
			{
				printf_s("Ошибка. Некорректно введены данные.\n ");
				while (getchar() != '\n');
			}			
				if (A[i] == 0)
					count++;
		}
		printf(" В массиве %d нулевых элементов. \n", count);
		delete A;
	system("pause");
	return 0;
}