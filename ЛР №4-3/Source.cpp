/*������� ������ ���������
������������ ������ �4
������� �3
������� :�������� ���������, ������� �� �������� � ���������� ������ ������� �����,
��������������� ������� ������, � ������� �� �� �����. */


#define _CRT_SECURE_NO_WARNINGS 
#define MAX_LENGTH		255

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <locale>

int amountOfFile(FILE *SourceFile);								// ������� �������� � �����
int fillMassiveFromFile(char *sentence, int size, int counter, FILE *myFile);		// ���������� ������� ������� �� �����
int deleteSpaces(char *sentence, int size);						// �������� �������� � ������ ��������� �� �������
int fillFileFromMassive(char *sentence, int size, FILE *finallFile);			// ���������� ����� ������� �� �������

void main() {
	system("chcp 1251");
	system("cls");

	FILE *SourceFile = fopen("File.txt", "r");
	FILE* finalFile = fopen("NewFile.txt", "w");
	

	fclose(NewFile);
	fclose(SourceFile);
}

int amountOfFile(FILE *SourceFile)
{
	int size = 0;
	for (int i = 0; fgetc(SourceFile) != EOF; i++)
		size = size + 1;
	return size;
}

int fillMassiveFromFile(char *sentence, int size, int counter, FILE *SourceFile)
{
	char M[] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',  '�' };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 13; j++) {
			sentence[i] = fgetc(SourceFile);
			if (sentence[i] == M[j] || sentence[i] == ' ' && sentence[i] == M[j])
				counter = counter + 1;
		}
	}
	return counter;
}

int fillFileFromMassive(char *sentence, int size, FILE *finalFile)
{
	for (int i = 0; i < size; i++)
		fprintf(finalFile, "%c", sentence[i]);
	return 0;
}