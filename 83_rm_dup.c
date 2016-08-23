#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	struct ListNode *newhead;
	struct ListNode **pprev = &newhead;
	while (head) {
		struct ListNode *next = head;
		head = head->next;
		while (head && next->val == head->val) {
			struct ListNode *t = head;
			head = head->next;
			free(t);
		}
		*pprev = next;
		pprev = &next->next;
	}
	*pprev = 0;
	return(newhead);
}

main(){}
