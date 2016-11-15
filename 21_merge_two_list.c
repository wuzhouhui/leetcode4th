struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *new = 0;
	struct ListNode **pp = &new, *t;

	while (l1 && l2) {
		if (l1->val < l2->val) {
			t = l1;
			l1 = l1->next;
		} else {
			t = l2;
			l2 = l2->next;
		}
		*pp = t;
		pp = &t->next;
	}
	while (l1) {
		t = l1;
		l1 = l1->next;
		*pp = t;
		pp = &t->next;
	}
	while (l2) {
		t = l2;
		l2 = l2->next;
		*pp = t;
		pp = &t->next;
	}
	*pp = 0;
	return(new);
}
main(){}
