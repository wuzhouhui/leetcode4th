#ifndef bool
#define bool int
#endif

bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize,
		int target)
{
	int r = 0, c = matrixColSize - 1;
	while (r < matrixRowSize && c >= 0) {
		if (matrix[r][c] == target)
			return(1);
		else if (matrix[r][c] < target)
			r++;
		else
			c--;
	}
	return(0);
}

main(){}
