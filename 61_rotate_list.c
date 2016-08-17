struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
	if (head == 0 || head->next == 0 || k <= 0)
		return(head);
	int	c;
	struct ListNode *p, *t;

	for (c = 0, p = head; p; p = p->next)
		c++;
	k %= c;
	if (k == 0)
		return(head);
	c -= k;
	for (p = head; c-- > 1; p = p->next)
		;
	t = p->next;
	p->next = 0;
	for (p = t; p->next; p = p->next)
		;
	p->next = head;
	return(t);
}

main(){}
