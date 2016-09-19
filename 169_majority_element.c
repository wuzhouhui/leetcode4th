int majorityElement(int *nums, int numsSize)
{
	int p, i, c;

	for (p = nums[0], i = 1, c = 1; i < numsSize; i++) {
		if (nums[i] == p)
			c++;
		else {
			c--;
			if (c == 0) {
				p = nums[i];
				c = 1;
			}
		}
	}
	return(p);
}
main(){}
