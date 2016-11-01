int removeElement(int *nums, int numsSize, int val)
{
	int i, j;

	for (i = j = 0; j < numsSize; j++)
		if (nums[j] == val)
			continue;
		else
			nums[i++] = nums[j];
	return(i);
}
main(){}
