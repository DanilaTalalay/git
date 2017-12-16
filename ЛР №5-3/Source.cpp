/*Талалай Данила Андреевич
КТбо 1-8
Лабораторная 5
Вариант 3
Написать программу, реализующую несколько алгоритмов сортировок,
и провести их сравнительный анализ на одном входном наборе данных.
Произвести сортировку алгоритмами: 
сортировка пузырьком,
сортировка расческой,
сортировка перемешиванием.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <time.h>

void booble(int *array_nomber, int nomber);
void cocktail(int *array_nomber, int nomber);
void comb(int *array_nomber, int nomber);

void main(void) {
	system ("chcp 1251");
	system("cls");

	FILE *file_is;
	file_is = fopen("text.txt", "r");
	int nomber = 0, s = 0;
	while ((fscanf(file_is, "%d", &s) != EOF)) {
		nomber++;
	}

	int *array_nomber = (int*) malloc(nomber * sizeof(int));
	rewind(file_is);

	for (int i = 0; i < nomber; i++) {
		fscanf(file_is, "%d", &array_nomber[i]);
	}
	fclose(file_is);

	printf("Отсортированно %d элементов\n", nomber);
	
	booble(array_nomber, nomber);
	cocktail(array_nomber, nomber);
	comb(array_nomber, nomber);


	free(array_nomber);
	_getch();
}
void booble(int *array_nomber, int nomber) {
	clock_t time;
	int m;

	time = clock();

	for (int i = 0; i < nomber; i++) {
		for (int j = 0; j < nomber - i - 1; j++) {
			if (array_nomber[j] > array_nomber[j + 1]) {
				m = array_nomber[j];
				array_nomber[j] = array_nomber[j + 1];
				array_nomber[j + 1] = m;
			}
		}
	}
	time = clock() - time;

	FILE *booble_file;
	booble_file = fopen("text_booble.txt", "w");
	for (int i = 0; i < nomber; i++) {
		fprintf(booble_file, "%d ", array_nomber[i]);
	}
	fclose(booble_file);

	printf("Сортировка пузырьком работала %f \n", (double)time / CLOCKS_PER_SEC);
}

void cocktail(int *array_nomber, int nomber) {
	clock_t time;
	int m;
	time = clock();
	int last = nomber - 1, left = 1, right = nomber - 1, j;

	do
	{
		for (j = right; j >= left; j--)
		{
			if (array_nomber[j - 1] > array_nomber[j])
			{
				m = array_nomber[j];
				array_nomber[j] = array_nomber[j + 1];
				array_nomber[j + 1] = m;
				last = j;
			}
		}
		left = last + 1;
		for (j = left; j <= right; j++)
		{
			if (array_nomber[j - 1] > array_nomber[j])
			{
				m = array_nomber[j];
				array_nomber[j] = array_nomber[j + 1];
				array_nomber[j + 1] = m;
				last = j;
			}
		}
		right = last - 1;
	} while (left < right);

	time = clock() - time;

	FILE *cocktail_file;
	cocktail_file = fopen("text_cocktail.txt", "w");
	for (int i = 0; i < nomber; i++) {
		fprintf(cocktail_file, "%d ", array_nomber[i]);
	}
	fclose(cocktail_file);

	printf("Сортировка перемешиванием работала %f \n", (double)time / CLOCKS_PER_SEC);
}

void comb(int *array_nomber, int nomber) {

	clock_t time;
	int m, k;

	time = clock();
	int s = nomber;
	long long cnt = 0;
	while (nomber>1) {
		s /= 1.247f; 
		if (s<1) s = 1; 
		k = 0; 
		for (int i = 0; i + s<nomber; ++i) { 
			if (array_nomber[i] / 10>array_nomber[i + s] / 10) {
				m = array_nomber[i];
				array_nomber[i] = array_nomber[i + s];
				array_nomber[i + s] = m;
				k = i;
			}
			++cnt;
		}
		if (s == 1) 
			nomber = k + 1;
	}
	
	time = clock() - time;

	FILE *comb_file;
	comb_file = fopen("text_comb.txt", "w");
	for (int i = 0; i < nomber; i++) {
		fprintf(comb_file, "%d ", array_nomber[i]);
	}
	fclose(comb_file);

	printf("Сортировка расческой работала %f \n", (double)time / CLOCKS_PER_SEC);
}