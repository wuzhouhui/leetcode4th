struct ListNode {
	int	val;
	struct ListNode *next;
};

void reorderList(struct ListNode *head)
{
	struct ListNode **pprev, *p, *t, *new, *rev;
	int	i, cnt;

	cnt = 0;
	for (p = head; p; p = p->next)
		cnt++;
	if (cnt < 3)
		return;
	cnt = (cnt % 2 == 0) ? cnt / 2 : cnt / 2 + 1;
	for (p = head, i = 1; i < cnt; i++)
		p = p->next;
	t = p->next;
	p->next = 0;
	p = t;

	for (rev = 0; p; ) {
		t = p;
		p = p->next;
		t->next = rev;
		rev = t;
	}

	pprev = &new;
	while (head) {
		*pprev = head;
		head = head->next;
		pprev = &(*pprev)->next;
		if (rev) {
			*pprev = rev;
			rev = rev->next;
			pprev = &(*pprev)->next;
		}
	}
	*pprev = 0;
}
main(){}
