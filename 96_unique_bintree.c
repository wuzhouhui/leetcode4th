#include <string.h>

int numTrees(int n)
{
	if (n < 0)
		return(0);
	int dp[n + 1];
	int i, j;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
			dp[i] += dp[j - 1] * dp[i - j];
	return(dp[n]);
}

main(){}
