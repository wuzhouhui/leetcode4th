int removeDuplicates(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return(0);

	int c = 1, k = 1, prev = nums[0], i;

	for (i = 1; i < numsSize; i++) {
		if (nums[i] != prev) {
			c = 1;
			prev = nums[i];
			nums[k++] = nums[i];
		} else if (c == 2) {
			continue;
		} else {
			c++;
			nums[k++] = nums[i];
		}
	}
	return(k);
}

main(){}
