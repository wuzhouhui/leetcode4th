#include <string.h>

static void reverse(char *s, int r)
{
	int l = 0;
	r--;
	while (l < r) {
		int c = s[l];
		s[l] = s[r];
		s[r] = c;
		l++, r--;
	}
}

int titleToNumber(char *s)
{
	int prod, res;

	reverse(s, strlen(s));
	prod = 1;
	res = 0;
	for (; *s; s++) {
		res += (*s - 'A' + 1) * prod;
		prod *= 26;
	}
	return(res);
}
main(){}
