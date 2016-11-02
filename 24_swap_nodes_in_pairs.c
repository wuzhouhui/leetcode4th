struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
	struct ListNode *newhead = 0;
	struct ListNode **pp = &newhead;

	while (head) {
		struct ListNode *p1 = head;
		head = head->next;
		struct ListNode *p2 = head;
		if (!head) {
			*pp = p1;
			pp = &p1->next;
			break;
		}
		head = head->next;
		*pp = p2;
		pp = &p2->next;
		*pp = p1;
		pp = &p1->next;
	}

	*pp = 0;
	return(newhead);
}
main(){}
