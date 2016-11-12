#include <string.h>

struct {
	int val, len;
	char *str;
} tbl[] = {
	{ 1000, 1, "M", },
	{ 900, 2, "CM", }, { 500, 1, "D", }, { 400, 2, "CD",}, { 100, 1, "C",},
	{ 90, 2, "XC", }, { 50, 1, "L", }, { 40, 2, "XL", }, { 10, 1, "X", },
	{ 9, 2, "IX", }, { 5, 1, "V", }, { 4, 2, "IV", }, { 1, 1, "I", },
};

int romanToInt(char *s)
{
	int res, i;

	res = 0;
	for (i = 0; i < sizeof(tbl) / sizeof(tbl[0]); i++) {
		while (strncmp(s, tbl[i].str, tbl[i].len) == 0) {
			res += tbl[i].val;
			s += tbl[i].len;
		}
	}
	return(res);
}
main(){}
