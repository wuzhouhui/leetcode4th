#ifndef bool
#define bool int
#endif

bool search(int *nums, int numsSize, int target)
{
	int left = 0, right = numsSize - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (nums[mid] == target)
			return(1);
		if (nums[left] < nums[right]) {
			if (target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		} else if (nums[left] > nums[right]) {
			if (nums[mid] >= nums[left]) {
				if (target <= nums[right])
					left = mid + 1;
				else if (target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			} else if (nums[mid] <= nums[right]) {
				if (target >= nums[left])
					right = mid - 1;
				else if (target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
		} else {
			left++;
		}
	}
	return(0);
}

main(){}
