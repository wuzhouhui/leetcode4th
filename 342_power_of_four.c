#ifndef bool
#define bool int
#endif

bool isPowerOfFour(int n)
{
	if (n <= 0)
		return(0);
	int i;
	for (i = 1; (n & (1 << i)) == 0; i++)
		;
	if (n == (1 << i) && i %2 == 0)
		return(1);
	return(0);
}
main()
{
	isPowerOfFour(8);
}
