/*Талалай Данила Андреевич
Лабораторная работа №3
Вариант №3
Задание :Написать программу, которая во вводимом с клавиатуры тексте выберет слова,
заканчивающиеся гласной буквой, и выведет их на экран. */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct Word {
	char data[255];
	int size;
	int count;
};
int sizeSTR(char *x) {
	int y = strlen(x);
	return y;
}
int amountM(char *x, int n) {
	int Amount = 0;
	char M[] = { 'й', 'у', 'е', 'ъ', 'ы', 'а', 'о', 'э', 'я', 'и', 'ь',  'ю' };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 13; j++){
			if (x[0] == M[j] || (x[i] == ' ' && x[i + 1] == M[j])) {
				Amount++;
			}
	}
	}
	return Amount;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Word words[10];
	int n = 3;
	printf("Введите слова \n");
	for (int i = 0; i < n; i++) {
		printf("Введите слово: ");
		scanf("%s", &words[i].data);
		words[i].size = sizeSTR(words[i].data);
	}

	int maxCount = 0;
		for (int i = 0; i < n; i++) {
			if (words[i].count > maxCount) {
				maxCount = words[i].count;
			}
			printf("Слово начинающиеся с гласной буквы :%s \n", words[i].data);
		}
		
	_getch();
	return 0;
}