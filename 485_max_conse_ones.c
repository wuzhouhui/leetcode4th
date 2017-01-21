int findMaxConsecutiveOnes(int *nums, int numsSize)
{
	int max, l, i;

	for (max = l = i = 0; i < numsSize; i++) {
		if (nums[i] == 0) {
			l = 0;
			continue;
		} else if (++l > max)
			max = l;
	}
	return(max);
}
main(){}
