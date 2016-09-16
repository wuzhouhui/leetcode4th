struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *sortList(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);

	struct ListNode *l1 = 0, *l2 = 0, *new = 0;
	struct ListNode **pp1, **pp2, *p;
	int	dir;

	pp1 = &l1;
	pp2 = &l2;
	dir = 1;
	while (head) {
		p = head;
		head = head->next;
		p->next = 0;
		if (dir) {
			*pp1 = p;
			pp1 = &p->next;
		} else {
			*pp2 = p;
			pp2 = &p->next;
		}
		dir = !dir;
	}

	l1 = sortList(l1);
	l2 = sortList(l2);

	pp1 = &new;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			p = l1;
			l1 = l1->next;
		} else {
			p = l2;
			l2 = l2->next;
		}
		p->next = 0;
		*pp1 = p;
		pp1 = &p->next;
	}
	if (l1)
		*pp1 = l1;
	if (l2)
		*pp1 = l2;
	return(new);
}
main(){}
