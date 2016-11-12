#include <string.h>

struct {
	int	val;
	char	*str;
} tbl[] = {
	{ 1000, "M", },
	{ 900, "CM", }, { 500, "D", }, { 400, "CD", }, { 100, "C", },
	{ 90, "XC", }, { 50, "L", }, { 40, "XL", }, { 10, "X", },
	{ 9, "IX", }, { 5, "V", }, { 4, "IV", }, { 1, "I", },
};

char *intToRoman(int num)
{
	char	buf[128] = { 0 };
	int	i = 0;

	while (num > 0) {
		while (num >= tbl[i].val) {
			num -= tbl[i].val;
			strcat(buf, tbl[i].str);
		}
		i++;
	}
	return(strdup(buf));
}

#include <stdio.h>

int main(void)
{
	printf("%s", intToRoman(10));
}
