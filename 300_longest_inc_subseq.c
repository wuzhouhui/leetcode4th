int lengthOfLIS(int *nums, int numsSize)
{
	if (numsSize < 2)
		return(numsSize);
	int dp[numsSize];
	int i, j, max = 1;

	for (i = 0; i < numsSize; i++)
		dp[i] = 1;
	for (i = 1; i < numsSize; i++)
		for (j = 0; j < i; j++) {
			int t;
			if (nums[j] >= nums[i])
				continue;
			else
				t = dp[j] + 1;
			if (t > dp[i])
				dp[i] = t;
			if (t > max)
				max = t;
		}
	return(max);
}
main(){}
