#include <stdio.h>
#include <string.h>

static void rev(char *s, int i, int j)
{
	while (i < j) {
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++, j--;
	}
}

char *convertToBase7(int num)
{
	char res[64] = { 0 };
	int p = 0;

	if (num < 0) {
		num = -num;
		res[p++] = '-';
	}
	do {
		int r = num % 7;
		num /= 7;
		res[p++] = r + '0';
	} while (num);
	if (res[0] == '-')
		rev(&res[0], 1, p - 1);
	else
		rev(&res[0], 0, p - 1);
	return(strdup(res));
}

int main(void)
{
	convertToBase7(-7);
}
