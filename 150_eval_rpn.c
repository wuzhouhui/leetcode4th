#include <stdlib.h>

static struct stack {
	int	val;
	struct stack *next;
} *stack;

static void push(int val)
{
	struct stack *t = malloc(sizeof(*t));
	t->val = val;
	t->next = stack;
	stack = t;
}

static int pop(void)
{
	struct stack *t = stack;
	int	val = t->val;
	stack = stack->next;
	free(t);
	return(val);
}

int evalRPN(char **tokens, int tokensSize)
{
	stack = 0;
	while (tokensSize--) {
		switch ((*tokens)[0]) {
			int a;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			if ((*tokens)[1] == 0) {
				a = pop();
				push(pop() - a);
			} else {
				push(atoi(*tokens));
			}
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			a = pop();
			push(pop() / a);
			break;
		default:
			push(atoi(*tokens));
			break;
		}
		tokens++;
	}
	return(pop());
}
main(){}
