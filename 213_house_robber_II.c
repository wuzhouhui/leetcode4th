static int do_rob(int *nums, int numsSize)
{
	if (numsSize < 1)
		return(0);
	int sum[numsSize];
	int i;

	for (i = 0; i < numsSize; i++) {
		if (i >= 2) {
			int t = sum[i - 2] + nums[i];
			sum[i] = t > sum[i - 1] ? t : sum[i - 1];
		} else if (i == 1) {
			sum[1] = nums[1] > nums[0] ? nums[1] : nums[0];
		} else {
			sum[0] = nums[0];
		}
	}
	return(sum[numsSize - 1]);
}

int rob(int *nums, int numsSize)
{
	if (numsSize == 1)
		return(nums[0]);
	int t1 = do_rob(nums, numsSize - 1);
	int t2 = do_rob(nums + 1, numsSize - 1);
	return(t1 > t2 ? t1 : t2);
}
main(){}
