struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA,
		struct ListNode *headB)
{
	struct ListNode *p;
	int	c1, c2;

	for (c1 = 0, p = headA; p; p = p->next)
		c1++;
	for (c2 = 0, p = headB; p; p = p->next)
		c2++;

	if (c1 > c2) {
		c1 -= c2;
		while (c1--)
			headA = headA->next;
	} else if (c1 < c2) {
		c2 -= c1;
		while (c2--)
			headB = headB->next;
	}

	while (headA != headB) {
		headA = headA->next;
		headB = headB->next;
	}

	return(headA);
}

main(){}
