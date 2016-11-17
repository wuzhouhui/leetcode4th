int searchInsert(int *nums, int numsSize, int target)
{
	int low = -1, high = numsSize;
	while (low + 1 != high) {
		int mid = (low + high) / 2;
		if (nums[mid] < target)
			low = mid;
		else
			high = mid;
	}
	return(high);
}
main(){}
