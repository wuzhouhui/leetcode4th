void rotate(int **matrix, int matrixRowSize, int matrixColSize)
{
	int up = 0, left = 0, down = matrixRowSize - 1,
	    right = matrixColSize - 1;
	while (up < down && left < right) {
		int i, len;
		len = right - left;
		for (i = 0; i < len; i++) {
			int t = matrix[up][left + i];
			matrix[up][left + i] = matrix[down - i][left];
			matrix[down - i][left] = matrix[down][right - i];
			matrix[down][right - i] = matrix[up + i][right];
			matrix[up + i][right] = t;
		}
		up++, left++, right--, down--;
	}
}

main(){}
