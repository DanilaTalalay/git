/*�������� ������� �.�.
���� 1-8
������������ ������ � 1
������� 9.
��������� �� ���������� � ������ � �������� � �������.*/

#include <stdio.h>
#include <cstdlib> 
#include <windows.h> 
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float d,l,v,b=0.00007; 
	printf_s ("������� ���������: "); 
	int x;
	do
	{
		x = scanf_s("%f", &d); 
		if (!x)
		{
			printf_s("������. ����������� ������� ������. \n ��������� ����: ");
			while (getchar () != '\n');
		}
		else
		{
			l = d*10.16; 
			printf("��������� � �������: %f * 10.16 = %f \n", d, l);
			v = l * b;
			printf("��������� � �������: %f * %f = %f \n", l, b, v);
		}
	} while (x != 1);
	system("pause"); 
	return 0;
}