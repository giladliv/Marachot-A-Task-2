#include "my_mat.h"


/**
 * @brief init and set a matrix by the input after that performs the Floyd-Warshall Algorithm
 * on the matrix
 * 
 * @param arr - 2d array with size of LENxLEN that all the index is in the 
 */
void initMat(int arr[][LEN])
{
	int isEOF = FALSE;
	for (int i = 0; i < LEN; i++)
	{
		for (int j = 0; j < LEN; j++)
		{
			if (isEOF)			// if end of file set the cell to be 0
			{
				arr[i][j] = 0;
			}
			else				// if not end of file get the cell's value by the user
			{
				isEOF = (scanf("%d", &arr[i][j]) == EOF);
			}
		}
	}
	FloydWarshallAlgo(arr);		// run the floyd warshall algorithm
}

/**
 * @brief get the minimum out of 2 integers
 * 
 * @param a first integer
 * @param b second integer
 * @return int the smallest integer out of the two
 */
int min(int a, int b)
{
	return (a < b ? a : b);
}

/**
 * @brief 
 * 
 * @param arr 
 */
void FloydWarshallAlgo(int arr[][LEN])
{
	for (int k = 0; k < LEN; k++)
	{
		for (int i = 0; i < LEN; i++)
		{
			for (int j = 0; j < LEN; j++)
			{
				if (!(arr[i][k] == 0 && i != k) && !(arr[k][j] == 0 && k != j)) 
					// if not inf i,k and if not inf k,j
				{
					if (arr[i][j] == 0 && i != j)	// if arr[i][j] is inf
					{
						arr[i][j] = arr[i][k] + arr[k][j];
						//A[i][j] = min(A[i][j], A[i][k] + A[k][j])
					}
					else
					{
						arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
					}
					
				}
				//else: it would be the same value
			}
		}
	}
}



void hasRoute(int arr[][LEN])
{
	int i = 0, j = 0;
	if (!(scanf(" %d %d", &i, &j) == EOF) && 
		0 <= i && i < LEN && 0 <= j && j < LEN)
	{
		printf("%s\n", (arr[i][j] ? "True" : "False"));
	}
	
}

void shortPath(int arr[][LEN])
{
	int i = 0, j = 0;
	if (!(scanf(" %d %d", &i, &j) == EOF) && 
		0 <= i && i < LEN && 0 <= j && j < LEN)
	{
		printf("%d\n", (arr[i][j] ? arr[i][j] : -1));
	}
	
}