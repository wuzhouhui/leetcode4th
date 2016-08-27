struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x)
{
	struct ListNode *lthead = 0, *gehead = 0;
	struct ListNode **ltprev = &lthead, **geprev = &gehead;
	while (head) {
		struct ListNode *p = head;
		head = head->next;
		if (p->val < x) {
			*ltprev = p;
			ltprev = &p->next;
		} else {
			*geprev = p;
			geprev = &p->next;
		}
	}
	*ltprev = gehead;
	*geprev = 0;
	return(lthead);
}

main(){}
