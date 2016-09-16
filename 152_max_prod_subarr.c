static inline int max(int a, int b)
{
	return(a > b ? a : b);
}

static inline int min(int a, int b)
{
	return(a < b ? a : b);
}

int maxProduct(int *nums, int numsSize)
{
	if (numsSize < 1)
		return(0);
	int glomax, locmax, locmin;
	int i;

	glomax = locmax = locmin = nums[0];
	for (i = 1; i < numsSize; i++) {
		int t1 = locmin;
		int t2 = locmax;
		locmax = max(max(nums[i], nums[i] * t2), nums[i] * t1);
		locmin = min(min(nums[i], nums[i] * t1), nums[i] * t2);
		glomax = max(locmax, glomax);
	}
	return(glomax);
}
main(){}
