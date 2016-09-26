#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int cmpfun(const void *a, const void *b)
{
	int i;
	static char bufa[64];
	static char bufb[64];
	const int *ai = a;
	const int *bi = b;

	sprintf(bufa, "%d%d", *ai, *bi);
	sprintf(bufb, "%d%d", *bi, *ai);
	for (i = 0; bufa[i]; i++)
		if (bufa[i] == bufb[i])
			continue;
		else
			return(bufb[i] - bufa[i]);
	return(0);
}

static int numlen(int num)
{
	int l = 0;
	do {
		l++;
		num /= 10;
	} while (num);
	return(l);
}

char *largestNumber(int *nums, int numsSize)
{
	int i, p, totlen;
	char *res;

	if (numsSize < 1)
		return(strdup("0"));
	qsort(nums, numsSize, sizeof(*nums), cmpfun);
	for (i = totlen = 0; i < numsSize; i++)
		totlen += numlen(nums[i]);
	res = calloc(totlen + 1, sizeof(*res));
	for (i = p = 0; i < numsSize; i++)
		p += sprintf(res + p, "%d", nums[i]);
	if (res[0] == '0')
		res[1] = 0;
	return(res);
}
main(){}
