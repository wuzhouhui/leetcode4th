#include <stdlib.h>
#include <string.h>

static void rev(char *s, int r)
{
	int l = 0;
	r--;
	while (l < r) {
		char c = s[l];
		s[l] = s[r];
		s[r] = c;
		l++, r--;
	}
}

static void asc2num(char *s, int l)
{
	while (l--)
		*s++ -= '0';
}

static void num2asc(char *s, int l)
{
	while (l--)
		*s++ += '0';
}

char *addBinary(char *a, char *b)
{
	int alen = strlen(a);
	int blen = strlen(b);
	char *res = malloc(((alen > blen ? alen : blen) + 2) * sizeof(*res));
	int c = 0, p = 0;

	if (alen == 0 && blen == 0)
		return(strdup("0"));
	if (alen == 0)
		return(strdup(b));
	if (blen == 0)
		return(strdup(a));
	rev(a, alen);
	rev(b, blen);
	asc2num(a, alen);
	asc2num(b, blen);
	while (alen && blen) {
		int t = *a + *b + c;
		c = 0;
		if (t > 1) {
			c = 1;
			t -= 2;
		}
		res[p++] = t;
		a++, b++, alen--, blen--;
	}
	while (alen) {
		int t = *a + c;
		c = 0;
		if (t > 1) {
			c = 1;
			t -= 2;
		}
		res[p++] = t;
		a++, alen--;
	}
	while (blen) {
		int t = *b + c;
		c = 0;
		if (t > 1) {
			c = 1;
			t -= 2;
		}
		res[p++] = t;
		b++, blen--;
	}
	if (c)
		res[p++] = c;
	res[p] = 0;
	rev(res, p);
	num2asc(res, p);
	return(res);
}

int main(void)
{
	char a[] = "11";
	char b[] = "11";
	char *res = addBinary(a, b);
}
