#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
	struct ListNode *newhead = 0;
	struct ListNode **pp = &newhead;
	while (head) {
		struct ListNode *t = head;
		head = head->next;
		if (t->val == val)
			free(t);
		else {
			*pp = t;
			pp = &t->next;
		}
	}
	*pp = 0;
	return(newhead);
}
main(){}
