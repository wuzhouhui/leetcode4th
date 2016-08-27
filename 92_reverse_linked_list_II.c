struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
	int	i;
	struct ListNode *revhead, *revlast, *last, *p;

	last = 0;
	for (p = head, i = 1; i < m; i++) {
		last = p;
		p = p->next;
	}
	revlast = revhead = 0;
	for (; i <= n; i++) {
		struct ListNode *t = p;
		p = p->next;
		if (revlast == 0)
			revlast = t;
		t->next = revhead;
		revhead = t;
	}
	if (last)
		last->next = revhead;
	revlast->next = p;
	return(last ? head : revhead);
}

main(){}
