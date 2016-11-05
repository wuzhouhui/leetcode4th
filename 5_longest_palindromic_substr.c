#include <string.h>

char *longestPalindrome(char *s)
{
	int	i, j, k;
	char	resbuf[1000] = { 0 };
	int	start, max = 0;

	for (i = 0; s[i]; i++) {
		int t = 1;
		for (j = i - 1, k = i + 1; j >= 0 && s[k] && s[j] == s[k]; j--,
				k++)
			t += 2;
		if (t > max) {
			start = ++j;
			max = t;
		}
		t = 0;
		for (j = i, k = i + 1; j >= 0 && s[k] && s[j] == s[k]; j--, k++)
			t += 2;
		if (t > max) {
			start = ++j;
			max = t;
		}
	}

	if (max == 0)
		return(strdup(""));
	else
		return(strndup(s + start, max));
}
main(){}
