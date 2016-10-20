int findDuplicate(int *nums, int numsSize)
{
	int low = 1, high = numsSize - 1;
	while (low < high) {
		int mid = (low + high) / 2, i;
		int le = 0, gt = 0;
		for (i = 0; i < numsSize; i++)
			if (nums[i] >= low && nums[i] <= mid)
				le++;
			else if (nums[i] > mid && nums[i] <= high)
				gt++;
		if (le > (mid - low + 1))
			high = mid;
		else
			low = mid + 1;
	}
	return(low);
}
main(){}
