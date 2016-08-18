#include <stdlib.h>

static void rev(int *arr, int r)
{
	int l = 0;
	r--;
	while (l < r) {
		int t = arr[l];
		arr[l] = arr[r];
		arr[r] = t;
		l++, r--;
	}
}

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int i, p, c, *res;

	if (digitsSize <= 0) {
		res = malloc(sizeof(*res));
		res[0] = 1;
		*returnSize = 1;
		return(res);
	}

	rev(digits, digitsSize);
	res = malloc((digitsSize + 1) * sizeof(*res));
	c = 1;
	p = 0;
	for (i = 0; i < digitsSize; i++) {
		int t = digits[i] + c; c = 0;
		if (t >= 10) {
			t -= 10;
			c = 1;
		}
		res[p++] = t;
	}
	if (c)
		res[p++] = c;
	rev(res, p);
	*returnSize = p;
	return(res);
}

int main(void)
{
	int arr[] = { 8, 9, 9, };
	int n;
	plusOne(arr, 3, &n);
	return(0);
}
