int findComplement(int num)
{
	if (num < 0)
		return(0);
	if (num == 0)
		return(1);
	int	res = 0, i = 0;
	while (num) {
		if ((num & 1) == 0)
			res += 1 << i;
		i++;
		num >>= 1;
	}
	return(res);
}
main(){}
