int firstMissingPositive(int *nums, int numsSize)
{
	if (nums == 0 || numsSize <= 0)
		return(1);
	int	i = 0;
	while (i < numsSize) {
		if (nums[i] > 0 && nums[i] <= numsSize && nums[i] != i + 1
				&& nums[nums[i] - 1] != nums[i]) {
			int t = nums[nums[i] - 1];
			nums[nums[i] - 1] = nums[i];
			nums[i] = t;
		} else
			i++;
	}
	for (i = 0; i < numsSize; i++)
		if (nums[i] != i + 1)
			return(i + 1);
	return(i + 1);
}

int main(void)
{
	int arr[] = { 1, 1, };
	return(firstMissingPositive(arr, sizeof(arr) / sizeof(arr[0])));
}
