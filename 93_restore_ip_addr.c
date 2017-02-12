#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char **res;
static int p, maxp;

static int str2int(const char *s, int len)
{
	int a = 0;
	while (len--)
		a = a * 10 + (*s++) - '0';
	return(a);
}

static void addans(const int *ip)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p] = malloc(16 * sizeof(**res));
	sprintf(res[p], "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
	p++;
}

static void do_restore(const char *s, int slen, int start, int *ip, int ipidx)
{
	int i;

	if (start == slen && ipidx == 4) {
		addans(ip);
		return;
	}
	if (start >= slen || ipidx >= 4)
		return;
	for (i = 1; i <= 3; i++) {
		int t = str2int(&s[start], i);
		if (!(t >= 0 && t <= 255))
			return;
		ip[ipidx] = t;
		do_restore(s, slen, start + i, ip, ipidx + 1);
		if (s[start] == '0')
			return;
	}
}

char **restoreIpAddresses(char *s, int *returnSize)
{
	int ip[4];

	res = NULL;
	p = maxp = 0;
	do_restore(s, strlen(s), 0, ip, 0);
	*returnSize = p;
	return(res);
}

int main(void)
{
}
