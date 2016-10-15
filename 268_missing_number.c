static inline void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int missingNumber(int *nums, int numsSize)
{
	int i;

	for (i = 0; i < numsSize; i++) {
		while (nums[i] < numsSize && nums[i] != i)
			swap(&nums[i], &nums[nums[i]]);
	}

	for (i = 0; i < numsSize; i++)
		if (nums[i] != i)
			return(i);
	return(numsSize);
}
main(){}
