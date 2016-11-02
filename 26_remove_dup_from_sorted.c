int removeDuplicates(int *nums, int numsSize)
{
	if (numsSize < 1)
		return(0);
	int i, j;
	int prev = nums[0];

	for (i = 1, j = 1; j < numsSize; j++)
		if (nums[j] == prev)
			continue;
		else {
			nums[i++] = nums[j];
			prev = nums[j];
		}
	return(i);
}
main(){}
