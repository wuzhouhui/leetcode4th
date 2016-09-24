#include <stdlib.h>
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

char *convertToTitle(int n)
{
	char buf[256] = { 0 }, *res;
	int i = 0;

	while (n) {
		int r = n % 26;
		n /= 26;
		if (r == 0) {
			r = 26;
			n--;
		}
		buf[i++] = r - 1 + 'A';
	}
	res = strdup(buf);
	reverse(res, strlen(res));
	return(res);
}

main(){}
