#include <stdio.h>
#include "my_mat.h"

void printArr(int arr[][LEN])
{
	for (int i = 0; i < LEN; i++)
	{
		for (int j = 0; j < LEN; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void menu()
{
	char ch = '0';
	int arr[LEN][LEN] = { 0 };

	
	do
	{
		fflush(stdin);
		if (scanf(" %c", &ch) == EOF)
		{
			ch = 'D';
		}

		switch (ch)
		{
			case 'A':
				initMat(arr);
				//printArr(arr);
				break;
			case 'B':
				hasRoute(arr);
				break;
			case 'C':
				shortPath(arr);
				break;
			default:
				break;
		}
		//printArr(arr);
	} while (ch != 'D');

}

//A 0 3 1 0 0 2 0 0 0 0 3 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 5 0 0 0 0 0 0 0 0 0 4 1 1 2 0 0 0 0 0 2 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 5 4 0 0 0 0 2 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 2 0 0 D
//{ {0, 3, 0, 7}, { 8, 0, 2, 0 }, { 5, 0, 0, 1 }, { 2, 0, 0, 0 } }


int main()
{	
	menu();
	
	

	return (0);
}