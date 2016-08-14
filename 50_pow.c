static double do_pow(double x, long int n)
{
	if (n == 0)
		return(1.0);
	if (n == 1)
		return(x);
	if (n & 1)
		return(x * do_pow(x, n - 1));
	x = do_pow(x, n >> 1);
	return(x * x);
}

double myPow(double x, int n)
{
	long int ln = n;
	if (ln < 0)
		ln = -ln;
	if (n >= 0)
		return(do_pow(x, ln));
	else
		return(1 / do_pow(x, ln));
}
main(){}
