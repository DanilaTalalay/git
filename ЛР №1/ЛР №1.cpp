/*Выполнил Талалай Д.А.
КТбо 1-8
Лабораторная работа № 1
Вариант 9.
Перевести из дециметров в ладони и выразить в верстах.*/

#include <stdio.h>
#include <cstdlib> 
#include <windows.h> 
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float d,l,v,b=0.00007; 
	printf_s ("Введите дециметры: "); 
	int x;
	do
	{
		x = scanf_s("%f", &d); 
		if (!x)
		{
			printf_s("Ошибка. Некорректно введены данные. \n Повторите ввод: ");
			while (getchar () != '\n');
		}
		else
		{
			l = d*10.16; 
			printf("Результат в ладонях: %f * 10.16 = %f \n", d, l);
			v = l * b;
			printf("Результат в верстах: %f * %f = %f \n", l, b, v);
		}
	} while (x != 1);
	system("pause"); 
	return 0;
}