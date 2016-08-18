void sortColors(int *nums, int numsSize)
{
	int arr[3] = { 0 };
	int i;
	for (i = 0; i < numsSize; i++)
		arr[nums[i]]++;
	for (i = 0; i < 3; i++) {
		while (arr[i]--)
			*nums++ = i;
	}
}
main(){}
