struct ListNode {
	int	val;
	struct ListNode *next;
};

static struct ListNode *reverse(struct ListNode *head)
{
	struct ListNode *new = 0;;

	while (head) {
		struct ListNode *t = head;
		head = head->next;
		t->next = new;
		new = t;
	}
	return(new);
}

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	if (k <= 1)
		return(head);

	struct ListNode *new = 0, **tail = &new;

	while (1) {
		int i;
		struct ListNode *t1, *t2;

		for (i = 1, t1 = head; i < k && t1; i++)
			t1 = t1->next;
		if (!t1) {
			*tail = head;
			break;
		}
		t2 = head;
		head = t1->next;
		t1->next = 0;
		t1 = reverse(t2);
		*tail = t1;
		tail = &t2->next;
	}

	return(new);
}

main(){}
