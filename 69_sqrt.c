#include <limits.h>

int mySqrt(int x)
{
	if (x <= 0)
		return(0);
	long l = 0, h = INT_MAX;
	while (l + 1 != h) {
		long mid = l + (h - l) / 2;
		long t = mid * mid;
		if (t == x)
			return(mid);
		else if (t < x)
			l = mid;
		else
			h = mid;
	}
	return(l);
}

main(){}
