int rob(int *nums, int numsSize)
{
	if (numsSize < 1)
		return(0);
	int sum[numsSize];
	int i;

	for (i = 0; i < numsSize; i++) {
		if (i >= 2) {
			int t = sum[i - 2] + nums[i];
			sum[i] = t > sum[i - 1] ? t : sum[i - 1];
		} else if (i == 1) {
			sum[1] = nums[1] > nums[0] ? nums[1] : nums[0];
		} else {
			sum[0] = nums[0];
		}
	}
	return(sum[numsSize - 1]);
}
int main(void)
{
	int arr[] = { 1, 1, 2, 1, };
	rob(arr, 4);
}
