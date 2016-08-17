int uniquePaths(int m, int n)
{
	static dp[100][100];
	int	i, j;

	if (m <= 0 || n <= 0)
		return(0);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
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
	return(dp[m - 1][n - 1]);
}

main(){}
