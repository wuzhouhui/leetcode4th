/*
 * runtime error.
 */
#include <stdlib.h>
#include <string.h>

static void reverse(char *s, int r)
{
	int l = 0;
	r--;
	while (l < r) {
		int t = s[l];
		s[l] = s[r];
		s[r] = t;
		l++, r--;
	}
}

static void asc2int(char *s, int l)
{
	while (l--)
		*s++ -= '0';
}

static void int2asc(char *s, int l)
{
	while (l--)
		*s++ += '0';
}

char *multiply(char *num1, char *num2)
{
	if (num1 == 0 || num2 == 0)
		return(strdup("0"));
	int l1 = strlen(num1), l2 = strlen(num2);
	char *res = malloc((l1 + l2 + 2) * sizeof(*res));
	char *buf = malloc((l1 + l2 + 2) * sizeof(*res));
	int i, j, t, c, bufp;

	if (l1 == 0 || l2 == 0 || num1[0] == '0' || num2[0] == '0')
		return(strdup("0"));
	reverse(num1, l1);
	reverse(num2, l2);
	asc2int(num1, l1);
	asc2int(num2, l2);
	for (i = 0; i < l1; i++) {
		c = 0;
		bufp = i;
		memset(buf, 0, bufp);
		for (j = 0; j < l2; j++) {
			t = num1[i] * num2[j] + c; c = 0;
			if (t >= 10) {
				c = t / 10;
				t %= 10;
			}
			buf[bufp++] = t;
		}
		if (c) {
			buf[bufp++] = c;
			c = 0;
		}
		for (j = i; j < bufp; j++) {
			t = buf[j] + res[j] + c; c = 0;
			if (t >= 10) {
				c = 1;
				t -= 10;
			}
			res[j] = t;
		}
		while (c) {
			t = res[j] + c; c = 0;
			if (t >= 10) {
				t -= 10;
				c = 1;
			}
			res[j++] = t;
		}
	}
	l1 += l2;
	reverse(res, l1);
	int2asc(res, l1);
	res[l1] = 0;
	free(buf);
	return(res);
}

#include <stdio.h>

int main(void)
{
	char n1[] = "202216";
	char n2[] = "90797663";
	printf("%s\n", multiply(n1, n2));
	return(0);
}
