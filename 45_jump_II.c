int jump(int *nums, int len)
{
	if (len <= 1)
		return(0);

	int res, start, next, max, i;

	res = start = 0;
	while (start < len - 1) {
		max = 1;
		next = start + 1;
		for (i = 1; i <= nums[start]; i++) {
			if (i + start >= len - 1)
				return(res + 1);
			int t = i + nums[start + i];
			if (t > max) {
				max = t;
				next = start + i;
			}
		}
		start = next;
		res++;
	}
	return(res);
}

int main(void)
{
	int arr[] = { 2, 3, 1, 1, 4, };
	return(jump(arr, sizeof(arr) / sizeof(arr[0])));
}
