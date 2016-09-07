#include <stdlib.h>
#include <string.h>

int *getRow(int rowIndex, int *returnSize)
{
	rowIndex++;

	if (rowIndex <= 0) {
		*returnSize = 0;
		return(0);
	}

	int *buf1 = malloc(rowIndex * sizeof(*buf1));
	int *buf2 = malloc(rowIndex * sizeof(*buf2));
	int i, j;

	for (i = 1; i <= rowIndex; i++) {
		for (j = 1; j <= i; j++) {
			if (j == 1 || j == i)
				buf2[j - 1] = 1;
			else
				buf2[j - 1] = buf1[j - 2] + buf1[j - 1];
		}
		memcpy(buf1, buf2, i * sizeof(*buf2));
	}
	*returnSize = rowIndex;
	free(buf2);
	return(buf1);
}
main(){}
