#include <string.h>

void setZeroes(int **matrix, int matrixRowSize, int matrixColSize)
{
	int i, j, rzero, czero;

	if (matrixRowSize == 0 || matrixColSize == 0)
		return;
	rzero = czero = 0;
	for (i = 0; i < matrixColSize; i++)
		if (matrix[0][i] == 0) {
			rzero = 1;
			break;
		}
	for (i = 0; i < matrixRowSize; i++)
		if (matrix[i][0] == 0) {
			czero = 1;
			break;
		}
	for (i = 1; i < matrixRowSize; i++) {
		for (j = 1; j < matrixColSize; j++) {
			if (matrix[i][j] == 0) {
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}
	for (i = 1; i < matrixColSize; i++) {
		if (matrix[0][i])
			continue;
		for (j = 1; j < matrixRowSize; j++)
			matrix[j][i] = 0;
	}
	for (i = 1; i < matrixRowSize; i++) {
		if (matrix[i][0])
			continue;
		memset(matrix[i], 0, matrixColSize * sizeof(int));
	}
	if (rzero)
		memset(matrix[0], 0, matrixColSize * sizeof(int));
	if (czero)
		for (i = 0; i < matrixRowSize; i++)
			matrix[i][0] = 0;
}

main(){}
