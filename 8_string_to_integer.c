#include <limits.h>

int myAtoi(char *str)
{
	long int res = 0;
	int	sign = 1;

	while (isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-') {
		sign = -1;
		str++;
	}
	while (*str && isdigit(*str)) {
		res = res * 10 + *str - '0';
		str++;
		if (res > INT_MAX)
			break;
	}
	res *= sign;
	if (res <= INT_MIN)
		return(INT_MIN);
	else if (res >= INT_MAX)
		return(INT_MAX);
	else
		return((int)res);
}
main(){}
