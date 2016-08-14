int maxSubArray(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return(0);
	int max, cur, i;

	max = cur = nums[0];
	for (i = 1; i < numsSize; i++) {
		int t = cur + nums[i];
		if (t > nums[i])
			cur = t;
		else
			cur = nums[i];
		if (cur > max)
			max = cur;
	}
	return(max);
}
main(){}
