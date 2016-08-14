#include <stdlib.h>

int *spiralOrder(int **matrix, int matrixRowSize, int matrixColSize)
{
	if (matrixRowSize <= 0 || matrixColSize <= 0)
		return(NULL);
	int up, left, down, right;
	int i, p;
	int *res;

	up = left = p = 0;
	down = matrixRowSize - 1;
	right = matrixColSize - 1;
	res = malloc(matrixRowSize * matrixColSize * sizeof(*res));
	while (up < down && left < right) {
		for (i = left; i < right; i++)
			res[p++] = matrix[up][i];
		for (i = up; i < down; i++)
			res[p++] = matrix[i][right];
		for (i = right; i > left; i--)
			res[p++] = matrix[down][i];
		for (i = down; i > up; i--)
			res[p++] = matrix[i][left];
		up++, left++, down--, right--;
	}
	if (up == down && left == right)
		res[p++] = matrix[up][up];
	else if (up == down) {
		for (i = left; i <= right; i++)
			res[p++] = matrix[up][i];
	} else if (left == right) {
		for (i = up; i <= down; i++)
			res[p++] = matrix[i][left];
	}
	return(res);
}
int main(void)
{
	int a[] = { 7 };
	int b[] = { 9 };
	int c[] = { 6 };
	int *d[] = { a, b, c, };
	int *res = spiralOrder(d, 3, 1);
	free(res);
}
