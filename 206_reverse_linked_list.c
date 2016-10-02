struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
	struct ListNode *newhead = 0;
	while (head) {
		struct ListNode *t = head;
		head = head->next;
		t->next = newhead;
		newhead = t;
	}
	return(newhead);
}
main(){}
