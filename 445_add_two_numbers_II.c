#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

static struct ListNode *rev(struct ListNode *l)
{
	struct ListNode *new = NULL;
	while (l) {
		struct ListNode *t = l;
		l = l->next;
		t->next = new;
		new = t;
	}
	return(new);
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *l3 = NULL;
	int	c;

	l1 = rev(l1);
	l2 = rev(l2);
	c = 0;
	while (l1 && l2) {
		int t = l1->val + l2->val + c;
		c = 0;
		l1 = l1->next;
		l2 = l2->next;
		if (t > 9) {
			c = 1;
			t -= 10;
		}
		struct ListNode *p = malloc(sizeof(*p));
		p->val = t;
		p->next = l3;
		l3 = p;
	}
	while (l1) {
		int t = l1->val + c;
		c = 0;
		l1 = l1->next;
		if (t > 9) {
			c = 1;
			t -= 10;
		}
		struct ListNode *p = malloc(sizeof(*p));
		p->val = t;
		p->next = l3;
		l3 = p;
	}
	while (l2) {
		int t = l2->val + c;
		c = 0;
		l2 = l2->next;
		if (t > 9) {
			c = 1;
			t -= 10;
		}
		struct ListNode *p = malloc(sizeof(*p));
		p->val = t;
		p->next = l3;
		l3 = p;
	}
	if (c) {
		struct ListNode *p = malloc(sizeof(*p));
		p->val = c;
		p->next = l3;
		l3 = p;
	}
	return(l3);
}

main(){}
