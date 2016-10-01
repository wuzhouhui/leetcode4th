#define testbit(a, b) (a & (1 << b))

int rangeBitwiseAnd(int m, int n)
{
	int i, res = 0;
	int diff = n - m;

	for (i = 0; i < 32; i++) {
		if (!testbit(m, i) || !testbit(n, i))
			continue;
		if (diff >= (1 << i) - (m & ((1 << i) - 1)))
			continue;
		res |= 1 << i;
	}

	return(res);
}
main(){}
