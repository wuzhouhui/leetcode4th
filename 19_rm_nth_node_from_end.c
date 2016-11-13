#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	struct ListNode *last, **pp;
	int	i;

	for (last = head; --n > 0;)
		last = last->next;
	pp = &head;
	while (last->next) {
		last = last->next;
		pp = &(*pp)->next;
	}
	last = *pp;
	*pp = last->next;
	free(last);
	return(head);
}
main(){}
