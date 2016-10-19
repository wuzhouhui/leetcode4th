#include <string.h>

int numSquares(int n)
{
	unsigned int dp[n + 1];
	int	i, j, t;

	memset(dp, 0xff, sizeof(dp));
	for (i = 1; (t = i * i) <= n; i++)
		dp[t] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; (t = i + j * j) <= n; j++) {
			int t1 = dp[i] + 1;
			if (t1 < dp[t])
				dp[t] = t1;
		}
	}
	return(dp[n]);
}
main(){}
