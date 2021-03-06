#include <stdio.h>
#include <conio.h> 
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int mas[5][5];
	int rez[5][5];
	int inner[3][3];
	int rezinner[3][3];
	int i = 0, j = 0, p1, p2, p3, p4, rowsize = 4, columnsize = 5, bite = 4, two = 2;
	_asm
	{
		mov ecx, 25          //ввод массива
		lea ebx, mas
		mov eax, 1
		n: mov [ebx], eax
		   add eax, 1
		   add ebx, 4
		   loop n
	}

	for (int i = 0; i < 5; i++) //вывод массива
	{
		for (int j = 0; j < 5; j++)
		{
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
   
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			inner[i][j] = mas[i+1][j+1];
		}
	}

	_asm
	{
		mov ecx, rowsize
		cycle :

		lea esi, mas
			mov eax, i
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, j
			mul bite
			add eax, ebx
			add esi, eax
			mov edx, [esi]
			mov p1, edx

			lea esi, mas
			mov eax, j
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, rowsize
			sub eax, i
			mul bite
			add eax, ebx
			add esi, eax
			mov edx, [esi]
			mov p2, edx

			lea esi, mas
			mov eax, rowsize
			sub eax, i
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, rowsize
			sub eax, j
			mul bite
			add eax, ebx
			add esi, eax
			mov edx, [esi]
			mov p3, edx

			lea esi, mas
			mov eax, rowsize
			sub eax, j
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, i
			mul bite
			add eax, ebx
			add esi, eax
			mov edx, [esi]
			mov p4, edx

			lea edi, rez
			mov eax, j
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, rowsize
			sub eax, i
			mul bite
			add eax, ebx
			add edi, eax
			mov ebx, p1
			mov[edi], ebx

			lea edi, rez
			mov eax, rowsize
			sub eax, i
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, rowsize
			sub eax, j
			mul bite
			add eax, ebx
			add edi, eax
			mov ebx, p2
			mov[edi], ebx

			lea edi, rez
			mov eax, rowsize
			sub eax, j
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, i
			mul bite
			add eax, ebx
			add edi, eax
			mov ebx, p3
			mov[edi], ebx

			lea edi, rez
			mov eax, i
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, j
			mul bite
			add eax, ebx
			add edi, eax
			mov ebx, p4
			mov[edi], ebx

			add j, 1
			dec ecx
			jnz cycle
	}

	rowsize = rowsize - 2;
	columnsize = columnsize - 2;
	i = 0;
	j = 0;

	_asm
	{
		    mov ecx, rowsize
			cycle1 :

		    lea esi, inner
			mov eax, i
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, j
			mul bite
			add eax, ebx
			add esi, eax
			mov edx, [esi]
			mov p1, edx

			lea esi, inner
			mov eax, j
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, rowsize
			sub eax, i
			mul bite
			add eax, ebx
			add esi, eax
			mov edx, [esi]
			mov p2, edx

			lea esi, inner
			mov eax, rowsize
			sub eax, i
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, rowsize
			sub eax, j
			mul bite
			add eax, ebx
			add esi, eax
			mov edx, [esi]
			mov p3, edx

			lea esi, inner
			mov eax, rowsize
			sub eax, j
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, i
			mul bite
			add eax, ebx
			add esi, eax
			mov edx, [esi]
			mov p4, edx

			lea edi, rezinner
			mov eax, j
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, rowsize
			sub eax, i
			mul bite
			add eax, ebx
			add edi, eax
			mov ebx, p3
			mov[edi], ebx

			lea edi, rezinner
			mov eax, rowsize
			sub eax, i
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, rowsize
			sub eax, j
			mul bite
			add eax, ebx
			add edi, eax
			mov ebx, p4
			mov[edi], ebx

			lea edi, rezinner
			mov eax, rowsize
			sub eax, j
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, i
			mul bite
			add eax, ebx
			add edi, eax
			mov ebx, p1
			mov[edi], ebx

			lea edi, rezinner
			mov eax, i
			mul columnsize
			mul bite
			mov ebx, eax
			mov eax, j
			mul bite
			add eax, ebx
			add edi, eax
			mov ebx, p2
			mov[edi], ebx

			add j, 1
			dec ecx
			jnz cycle1
	}

	rezinner[1][1] = mas[2][2];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
	       rez[i + 1][j + 1] = rezinner[i][j];
		}
	}

	for (int i = 0; i < 5; i++) //вывод массива
	{
		for (int j = 0; j < 5; j++)
		{
			cout << rez[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

    _getch();
}
