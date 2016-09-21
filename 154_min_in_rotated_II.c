int findMin(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return(0);

	int l = 0, r = numsSize - 1;

	while (l != r && nums[l] >= nums[r]) {
		int mid = (l + r) / 2;
		if (nums[l] == nums[r]) {
			if (nums[mid] == nums[r]) {
				l++;
				continue;
			} else if (nums[mid] > nums[l])
				l = mid + 1;
			else
				r = mid;
		} else {
			if (nums[mid] >= nums[l])
				l = mid + 1;
			else
				r = mid;
		}
	}

	return(nums[l]);
}
main(){}
