int climbStairs(int n)
{
	if (n <= 0)
		return(1);
	int f0 = 1, f1 = 1;
	int i;
	for (i = 2; i <= n; i++) {
		int t = f0 + f1;
		f0 = f1;
		f1 = t;
	}
	return(f1);
}

main(){}
