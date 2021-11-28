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
 * @brief apllies the Floyd-Warshall algorithm on matrix with size of (LENxLEN) = (10x10). 
 * For no connection between 2 vertexs we will still remains on 0, but we will consider it as 'inf'
 * if not has the same row,col number.
 * the function works like that:
 * A(i,j)_{k} = min { A(i,j)_{k-1} ,  A(i,k)_{k-1} + A(k,j)_{k-1} }
 * 
 * @param arr matrix with size of (LENxLEN) = (10x10)
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
					// if arr[i][k] is not 'inf'  AND  arr[k][j] if not 'inf'
				{
					if (arr[i][j] == 0 && i != j)	// if arr[i][j] is 'inf'
					{
						arr[i][j] = arr[i][k] + arr[k][j];	// this is the minimal value
					}
					else
					{
						arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
						//according to FW algorithm gets the minimum between the two
					}
					
				}
				//else: it would be the same value
			}
		}
	}
}


/**
 * @brief Gets 2 indexs from the user,
 * Prints "True" if there is a path through 2 points,
 * "False" if there is no path
 * 
 * @param arr matrix with size of (LENxLEN) = (10x10)
 */
void hasRoute(int arr[][LEN])
{
	int i = 0, j = 0;
	if (!(scanf("%d%d", &i, &j) == EOF) && 			// gets the indexs and check if not end of file
		0 <= i && i < LEN && 0 <= j && j < LEN)		// checks if indexs are in boundries of the matrix
	{
		printf("%s\n", (arr[i][j] ? "True" : "False"));
	}
	
}

/**
 * @brief Gets 2 indexs from the user,
 * Prints the path length if there is a path through 2 points,
 * (-1) if there is no path
 * 
 * @param arr matrix with size of (LENxLEN) = (10x10)
 */
void shortPath(int arr[][LEN])
{
	int i = 0, j = 0;
	if (!(scanf("%d%d", &i, &j) == EOF) && 		// gets the indexs and check if not end of file
		0 <= i && i < LEN && 0 <= j && j < LEN)	// checks if indexs are in boundries of the matrix
	{
		printf("%d\n", (arr[i][j] ? arr[i][j] : -1));
	}
	
}