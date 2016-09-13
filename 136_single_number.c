int singleNumber(int *nums, int numsSize)
{
	int i, r = 0;

	for (i = 0; i < numsSize; i++)
		r ^= nums[i];
	return(r);
}
main(){}
