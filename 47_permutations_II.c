#include <stdlib.h>
#include <string.h>

static int **res, p, maxp;

static void addans(int *buf, int len)
{
	int i;
	for (i = 0; i < p; i++)
		if (!memcmp(res[i], buf, len * sizeof(buf[0])))
			return;

	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p] = malloc(len * sizeof(res[p][0]));
	memcpy(res[p++], buf, len * sizeof(buf[0]));
}

static void do_perm(int *nums, int len, int *buf, char *occupy, int start)
{
	if (start >= len) {
		addans(buf, len);
		return;
	}
	int i;
	for (i = 0; i < len; i++) {
		if (occupy[i])
			continue;
		occupy[i] = 1;
		buf[start] = nums[i];
		do_perm(nums, len, buf, occupy, start + 1);
		occupy[i] = 0;
	}
}

int **permuteUnique(int *nums, int numsSize, int *returnSize)
{
	if (numsSize <= 0) {
		*returnSize = 0;
		return(NULL);
	}
	char occupy[numsSize];
	int buf[numsSize];

	res = NULL;
	maxp = p = 0;
	memset(occupy, 0, sizeof(occupy));
	do_perm(nums, numsSize, buf, occupy, 0);
	*returnSize = p;
	return(res);
}

int main(void)
{
	int arr[] = { 1, 1, 2, };
	int n;
	int **res = permuteUnique(arr, 3, &n);
}
