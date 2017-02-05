#include <limits.h>

int divide(int dividend, int divisor)
{
	if (divisor == 0)
		return(dividend < 0 ? INT_MIN : INT_MAX);
	if (divisor == 1)
		return(dividend);
	if (divisor == -1)
		return(dividend == INT_MIN ? INT_MAX : -dividend);

	long int ldividend = dividend, ldivisor = divisor;
	int	shift, res = 0;

	if (ldividend < 0)
		ldividend = -ldividend;
	if (ldivisor < 0)
		ldivisor = -ldivisor;
	while (ldividend >= ldivisor) {
		shift = 0;
		while ((ldivisor << shift) <= ldividend)
			shift++;
		shift--;
		res += 1 << shift;
		ldividend -= ldivisor << shift;
	}

	if ((dividend >= 0) ^ (divisor >= 0))
		res = -res;
	return(res);
}

main(){}
