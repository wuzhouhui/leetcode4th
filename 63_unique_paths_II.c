int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridRowSize,
		int obstacleGridColSize)
{
	static dp[100][100];
	int	i, j;

	if (obstacleGridRowSize <= 0 || obstacleGridColSize <= 0)
		return(0);
	for (i = 0; i < obstacleGridRowSize; i++) {
		for (j = 0; j < obstacleGridColSize; j++) {
			if (obstacleGrid[i][j]) {
				dp[i][j] = 0;
				continue;
			}

			if (i && j)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			else if (i == 0 && j == 0)
				dp[i][j] = 1;
			else if (i == 0)
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return(dp[obstacleGridRowSize - 1][obstacleGridColSize - 1]);
}

main(){}
