int minSubArrayLen(int s, int *nums, int numsSize)
{
	if (numsSize < 1)
		return(0);

	int res = 0, l = 0, r = 0, sum = nums[0];

	while (r < numsSize) {
		while (r + 1 < numsSize && sum < s)
			sum += nums[++r];
		if (sum < s)
			break;

		while (l <= r && sum >= s)
			sum -= nums[l++];
		int t = r - l + 2;
		if (res == 0 || t < res)
			res = t;
		if (++r >= numsSize)
			break;
		sum += nums[r];
	}

	return(res);
}
main(){}
