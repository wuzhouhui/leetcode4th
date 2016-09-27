#include <stdint.h>

int hammingWeight(uint32_t n)
{
	int res = 0;
	while (n) {
		res++;
		n &= n - 1;
	}
	return(res);
}
main(){}
