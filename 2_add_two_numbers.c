#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *res = NULL;
	struct ListNode **tailp = &res;
	int	c = 0;

	while (l1 && l2) {
		int t = l1->val + l2->val + c;
		l1 = l1->next;
		l2 = l2->next;
		if (t > 9) {
			t -= 10;
			c = 1;
		} else
			c = 0;
		*tailp = malloc(sizeof(**tailp));
		(*tailp)->val = t;
		tailp = &(*tailp)->next;
	}
	while (l1) {
		int t = l1->val + c;
		l1 = l1->next;
		if (t > 9) {
			t -= 10;
			c = 1;
		} else
			c = 0;
		*tailp = malloc(sizeof(**tailp));
		(*tailp)->val = t;
		tailp = &(*tailp)->next;
	}
	while (l2) {
		int t = l2->val + c;
		l2 = l2->next;
		if (t > 9) {
			t -= 10;
			c = 1;
		} else
			c = 0;
		*tailp = malloc(sizeof(**tailp));
		(*tailp)->val = t;
		tailp = &(*tailp)->next;
	}
	if (c) {
		*tailp = malloc(sizeof(**tailp));
		(*tailp)->val = c;
		tailp = &(*tailp)->next;
	}
	*tailp = 0;
	return(res);
}
main(){}
