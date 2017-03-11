int getSum(int a, int b)
{
	while (1) {
		int t = a ^ b;
		b = (a & b) << 1;
		a = t;
		if (b == 0)
			break;
	}
	return(a);
}

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", getSum(atoi(argv[1]), atoi(argv[2])));
	return(0);
}
