int minPathSum(int **grid, int gridRowSize, int gridColSize)
{
	if (gridRowSize <= 0 || gridColSize <= 0)
		return(0);

	int	i, j;

	for (i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (i && j) {
				int t1 = grid[i][j] + grid[i - 1][j];
				int t2 = grid[i][j] + grid[i][j - 1];
				grid[i][j] = (t1 < t2 ? t1 : t2);
			} else if (i == 0 && j) {
				grid[i][j] += grid[i][j - 1];
			} else if (i && j == 0) {
				grid[i][j] += grid[i - 1][j];
			}
		}
	}
	return(grid[gridRowSize - 1][gridColSize - 1]);
}

main(){}
