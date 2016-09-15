struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head)
{
	struct ListNode *new = 0, **pprev, *p;

	while (head) {
		p = head;
		head = head->next;
		pprev = &new;
		while (*pprev && (*pprev)->val < p->val)
			pprev = &(*pprev)->next;
		p->next = *pprev;
		*pprev = p;
	}
	return(new);
}
main(){}
