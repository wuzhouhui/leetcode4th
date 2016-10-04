int maximalSquare(char **matrix, int matrixRowSize, int matrixColSize)
{
	int square[matrixRowSize][matrixColSize];
	int res = 0, i, j;

	for (i = 0; i < matrixRowSize; i++) {
		for (j = 0; j < matrixColSize; j++) {
			if (!i || !j)
				square[i][j] = (matrix[i][j] == '1');
			else if (matrix[i][j] == '0')
				square[i][j] = 0;
			else if (matrix[i - 1][j] == '0' ||
					matrix[i][j - 1] == '0')
				square[i][j] = 1;
			else {
				int t = square[i - 1][j - 1];
				if (t > square[i - 1][j])
					t = square[i - 1][j];
				if (t > square[i][j - 1])
					t = square[i][j - 1];
				square[i][j] = t + 1;
			}
			int t = square[i][j] * square[i][j];
			if (t > res)
				res = t;
		}
	}

	return(res);
}
main(){}
