int calculate(char *s)
{
	int sum = 0;
	int term = 1;
	int last = 0;
	int op = '*';

	while (*s) {
		switch (*s) {
		case ' ':
			s++;
			break;
		case '+':
			sum += term;
			term = 1;
			last = 0;
			op = '*';
			s++;
			break;
		case '-':
			sum += term;
			term = -1;
			last = 0;
			op = '*';
			s++;
			break;
		case '*':
			op = '*';
			s++;
			break;
		case '/':
			op = '/';
			s++;
			break;
		default:
			last = 1;
			int t = 0;
			while (isdigit(*s))
				t = t * 10 + (*s++) - '0';
			if (op == '*')
				term *= t;
			else
				term /= t;
			break;
		}
	}

	if (last)
		sum += term;
	return(sum);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", calculate(argv[1]));
	return(0);
}
