static void do_trans(char **grid, int row, int col, int i, int j)
{
	if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != '1')
		return;
	grid[i][j] = 0;
	do_trans(grid, row, col, i - 1, j);
	do_trans(grid, row, col, i + 1, j);
	do_trans(grid, row, col, i, j - 1);
	do_trans(grid, row, col, i, j + 1);
}

int numIslands(char **grid, int gridRowSize, int gridColSize)
{
	int i, j, tot = 0;

	for (i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (grid[i][j] != '1')
				continue;
			tot++;
			do_trans(grid, gridRowSize, gridColSize, i, j);
		}
	}

	return(tot);
}
main(){}
