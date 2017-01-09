#include <string.h>
#include <stdlib.h>

static void rev(char *str, int j)
{
	int i = 0;
	j--;
	while (i < j) {
		int t = str[i];
		str[i] = str[j];
		str[j] = t;
		i++, j--;
	}
}

static void asc2dec(char *str, int len)
{
	while (len--)
		*str++ -= '0';
}

char *addStrings(char *num1, char *num2)
{
	char res[5101] = { 0 };
	int i, p, c, t, l1, l2;

	l1 = strlen(num1);
	l2 = strlen(num2);
	p = c = 0;
	rev(num1, l1);
	rev(num2, l2);
	asc2dec(num1, l1);
	asc2dec(num2, l2);
	for (i = 0; i < l1 && i < l2; i++) {
		t = c + num1[i] + num2[i];
		c = 0;
		if (t > 9) {
			t -= 10;
			c = 1;
		}
		res[p++] = t + '0';
	}
	for (; i < l1; i++) {
		t = c + num1[i];
		c = 0;
		if (t > 9) {
			t -= 10;
			c = 1;
		}
		res[p++] = t + '0';
	}
	for (; i < l2; i++) {
		t = c + num2[i];
		c = 0;
		if (t > 9) {
			t -= 10;
			c = 1;
		}
		res[p++] = t + '0';
	}
	if (c)
		res[p++] = c + '0';
	rev(res, p);
	return(strdup(res));
}

int main(int argc, char *argv[])
{
	addStrings(argv[1], argv[2]);
}
