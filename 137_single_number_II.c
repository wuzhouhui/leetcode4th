int singleNumber(int *nums, int numsSize)
{
	int one = nums[0];
	int two = 0;
	int i;

	for (i = 1; i < numsSize; i++) {
		two |= one & nums[i];
		one ^= nums[i];
		int t = one & two;
		one &= ~t;
		two &= ~t;
	}
	return(one);
}
main(){}
