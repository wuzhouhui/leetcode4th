int findMin(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return(0);

	int l = 0, r = numsSize - 1;

	while (nums[l] > nums[r]) {
		int m = (l + r) / 2;
		if (nums[m] >= nums[l])
			l = m + 1;
		else
			r = m;
	}
	return(nums[l]);
}
main(){}
