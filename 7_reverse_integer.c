#include <limits.h>

int reverse(int x)
{
	long int lx = x;
	long int res = 0;
	int	sign = 1;

	if (lx < 0) {
		lx = -lx;
		sign = -1;
	}
	while (lx) {
		res = res * 10 + lx % 10;
		lx /= 10;
	}
	res *= sign;
	if (res < 0 && res < INT_MIN)
		return(0);
	if (res > INT_MAX)
		return(0);
	return((int)res);
}
main(){}
