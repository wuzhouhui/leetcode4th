/*
 * Memory limit exceeded
 */

int islandPerimeter(int **grid, int gridRowSize, int gridColSize)
{
	int i, j, res;

	for (res = i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (grid[i][j] == 0)
				continue;
			if (j == 0 || grid[i][j - 1] == 0)
				res++;
			if (j == gridColSize - 1 || grid[i][j + 1] == 0)
				res++;
			if (i == 0 || grid[i - 1][j] == 0)
				res++;
			if (i == gridRowSize - 1 || grid[i + 1][j] == 0)
				res++;
		}
	}

	return(res);
}
main(){}
