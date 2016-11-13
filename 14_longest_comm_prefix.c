#include <string.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
	return(strcmp(*(char **)a, *(char **)b));
}

static int commlen(const char *s1, const char *s2)
{
	int r = 0;
	while (*s1 && *s1++ == *s2++)
		r++;
	return(r);
}

char *longestCommonPrefix(char **strs, int strsSize)
{
	if (strsSize < 1)
		return(strdup(""));

	int	i, maxlen = strlen(strs[0]);
	char	*str = strs[0];

	qsort(strs, strsSize, sizeof(strs[0]), cmp);
	for (i = 1; i < strsSize; i++) {
		int t = commlen(strs[i - 1], strs[i]);
		if (t < maxlen) {
			maxlen = t;
			str = strs[i];
		}
	}
	return(strndup(str, maxlen));
}
main(){}
