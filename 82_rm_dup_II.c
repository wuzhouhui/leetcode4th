#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	struct ListNode *newhead;
	struct ListNode **pprev = &newhead;
	while (head) {
		struct ListNode *next = head;
		int prevval = next->val;
		head = head->next;
		while (head && head->val == prevval) {
			if (next)
				free(next);
			next = 0;
			struct ListNode *t = head;
			head = head->next;
			free(t);
		}
		if (next) {
			*pprev = next;
			pprev = &next->next;
		}
	}
	*pprev = 0;
	return(newhead);
}
main(){}
