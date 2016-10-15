#include <stdlib.h>

static int cmpfun(const void *a, const void *b)
{
	return(*(int *)b - *(int *)a);
}

int hIndex(int *citations, int citationsSize)
{
	int i;

	qsort(citations, citationsSize, sizeof(citations[0]), cmpfun);
	for (i = 1; i <= citationsSize; i++)
		if (citations[i - 1] < i)
			break;
	return(i - 1);
}
main(){}
