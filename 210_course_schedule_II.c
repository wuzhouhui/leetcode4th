#include <string.h>
#include <stdlib.h>

int *findOrder(int numCourse, int **prerequisites, int prerequisitesRowSize,
		int prerequisitesColSize, int *returnSize)
{
	int in[numCourse];
	int i, next, left, p = 0;
	int *res = malloc(numCourse * sizeof(*res));

	memset(in, 0, sizeof(in));
	for (i = 0; i < prerequisitesRowSize; i++)
		in[prerequisites[i][0]]++;

	*returnSize = numCourse;
	left = numCourse;
	while (left > 0) {
		for (i = 0; i < numCourse; i++)
			if (in[i] == 0)
				break;
		if (i >= numCourse) {
			*returnSize = 0;
			free(res);
			return(NULL);
		}
		res[p++] = i;
		next = i;
		left--;
		in[next] = -1;
		for (i = 0; i < prerequisitesRowSize; i++) {
			if (prerequisites[i][1] != next)
				continue;
			else
				in[prerequisites[i][0]]--;
		}
	}

	return(res);
}
main(){}
