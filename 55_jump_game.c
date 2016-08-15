#ifndef bool
#define bool int
#endif

bool canJump(int *nums, int numsSize)
{
	if (numsSize <= 1)
		return(1);
	int start = 0;
	while (1) {
		int next = -1, max = -1, i;
		for (i = 1; i <= nums[start]; i++) {
			if (start + i >= numsSize - 1)
				return(1);
			int t = i + nums[start + i];
			if (t > max) {
				max = t;
				next = i + start;
			}
		}
		if (next < 0)
			return(0);
		start = next;
	}
}

#include <stdio.h>
#define ARRSZ(a) (sizeof(a) / sizeof(a[0]))

int main(void)
{
	int arr1[] = { 2, 3, 1, 1, 4, };
	int arr2[] = { 3, 2, 1, 0, 4, };
	printf("%d %d\n", canJump(arr1, ARRSZ(arr1)),
			canJump(arr2, ARRSZ(arr2)));
	return(0);
}
