#include <stdlib.h>
#include <string.h>

static char **res;
static int maxp, p;

static void addans(const char *buf, int len)
{
	if (len < 1)
		return;
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = strndup(buf, len);
}

static void do_comb(const char *s, int level, char *buf)
{
	static char *tbl[] = {
		"",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz",
	};
	int	i;

	if (*s == 0) {
		addans(buf, level);
		return;
	}
	if (*s == '0' || *s == '1') {
		do_comb(s + 1, level, buf);
		return;
	}
	for (i = 0; tbl[*s - '0'][i]; i++) {
		buf[level] = tbl[*s - '0'][i];
		do_comb(s + 1, level + 1, buf);
	}
}

char **letterCombinations(char *digits, int *returnSize)
{
	char buf[128];

	res = NULL;
	maxp = p = 0;
	do_comb(digits, 0, buf);
	*returnSize = p;
	return(res);
}

int main(void)
{
	char *s = "012";
	int n;
	char **res;
	res = letterCombinations(s, &n);
}
