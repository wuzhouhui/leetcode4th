int nthUglyNumber(int n)
{
	if (n < 1)
		return(0);

	int dp[n], i;
	int k2, k3, k5;

	k2 = k3 = k5 = 0;
	dp[0] = 1;
	for (i = 1; i < n; i++) {
		int t2 = dp[k2] * 2;
		int t3 = dp[k3] * 3;
		int t5 = dp[k5] * 5;
		int next = t2;
		if (t3 < next)
			next = t3;
		if (t5 < next)
			next = t5;
		dp[i] = next;
		if (t2 == next)
			k2++;
		if (t3 == next)
			k3++;
		if (t5 == next)
			k5++;
	}

	return(dp[n - 1]);
}
main(){}
