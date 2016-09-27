#include <stdint.h>

static char map[] = {
	0, 8, 4, 12,
	2, 10, 6, 14,
	1, 9, 5, 13,
	3, 11, 7, 15,
};

uint32_t reverseBits(uint32_t n)
{
	uint32_t res = 0;
	int	mask = 0xf;
	res += map[n & mask]; n >>= 4; res <<= 4;
	res += map[n & mask]; n >>= 4; res <<= 4;
	res += map[n & mask]; n >>= 4; res <<= 4;
	res += map[n & mask]; n >>= 4; res <<= 4;
	res += map[n & mask]; n >>= 4; res <<= 4;
	res += map[n & mask]; n >>= 4; res <<= 4;
	res += map[n & mask]; n >>= 4; res <<= 4;
	res += map[n & mask];
	return(res);
}
main(){}
