#include <string.h>

#ifndef bool
#define bool int
#endif

bool canFinish(int numCourse, int **prerequisites, int prerequisitesRowSize,
		int prerequisitesColSize)
{
	int in[numCourse];
	int i, next, left;

	memset(in, 0, sizeof(in));
	for (i = 0; i < prerequisitesRowSize; i++)
		in[prerequisites[i][0]]++;

	left = numCourse;
	while (left > 0) {
		for (i = 0; i < numCourse; i++)
			if (in[i] == 0)
				break;
		if (i >= numCourse)
			return(0);

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

	return(1);
}
main(){}
