int findPeakElement(int *nums, int numsSize)
{
	int l = -1, r = numsSize;

	while (1) {
		int m = (l + r) / 2;

		if (m - 1 == -1 && m + 1 == numsSize)
			return(m);
		else if (m - 1 == -1) {
			if (nums[m] > nums[m + 1])
				return(m);
			else
				l = m;
		} else if (m + 1 == numsSize) {
			if (nums[m] > nums[m - 1])
				return(m);
			else
				r = m;
		} else if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
			return(m);
		else if (nums[m] < nums[m - 1] && nums[m] < nums[m + 1])
			l = m + 1;
		else if (nums[m] > nums[m - 1])
			l = m;
		else
			r = m;
	}
}
void main(void)
{
}
