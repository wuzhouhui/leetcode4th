#include <ctype.h>
#include <string.h>
#include <stdlib.h>

static char keyboard[] = {
	1, 2, 2, 1, 0,
	1, 1, 1, 0, 1,
	1, 1, 2, 2, 0,
	0, 0, 0, 1, 0,
	0, 2, 0, 2, 0,
	2,
};

static char **res;
static int curlen, maxlen;

static void addans(const char *s)
{
	if (curlen >= maxlen) {
		maxlen += 8;
		res = realloc(res, maxlen * sizeof(*res));
	}
	res[curlen++] = strdup(s);
}

char **findWords(char **words, int wordsSize, int *returnSize)
{
	int i, j;

	res = 0;
	curlen = maxlen = 0;
	for (i = 0; i < wordsSize; i++) {
		char prev = keyboard[tolower(words[i][0]) - 'a'];
		for (j = 1; words[i][j]; j++)
			if (keyboard[tolower(words[i][j]) - 'a'] != prev)
				break;
		if (words[i][j])
			continue;
		addans(words[i]);
	}
	*returnSize = curlen;
	return(res);
}

main(){}
