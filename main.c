#include <stdio.h>
#include "my_mat.h"


int main()
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
	

	return (0);
}