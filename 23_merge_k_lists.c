struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
	if (listsSize <= 0)
		return(0);
	if (listsSize == 1)
		return(lists[0]);

	int mid = listsSize / 2;
	struct ListNode *l1, *l2, *l3 = 0, **tail = &l3;

	l1 = mergeKLists(&lists[0], mid);
	l2 = mergeKLists(&lists[mid], listsSize - mid);
	while (l1 && l2) {
		struct ListNode *t;
		if (l1->val < l2->val) {
			t = l1;
			l1 = l1->next;
		} else {
			t = l2;
			l2 = l2->next;
		}
		*tail = t;
		tail = &t->next;
	}
	*tail = 0;
	if (l1)
		*tail = l1;
	else if (l2)
		*tail = l2;
	return(l3);
}
main(){}
