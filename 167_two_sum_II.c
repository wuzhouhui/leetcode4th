#include <stdlib.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
	int l = 0, r = numbersSize - 1;

	while (l < r) {
		int t = numbers[l] + numbers[r];
		if (t == target) {
			int *res = malloc(sizeof(*res) << 1);
			res[0] = l + 1;
			res[1] = r + 1;
			*returnSize = 2;
			return(res);
		} else if (t < target)
			l++;
		else
			r--;
	}

	*returnSize = 0;
	return(NULL);
}
main(){}
