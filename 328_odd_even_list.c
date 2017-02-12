struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *oddEvenList(struct ListNode *head)
{
	struct ListNode *odd = 0, **oddtail = &odd;
	struct ListNode *even = 0, **eventail = &even;
	int	isodd = 1;

	while (head) {
		struct ListNode *t = head;
		head = head->next;
		if (isodd) {
			*oddtail = t;
			oddtail = &t->next;
		} else {
			*eventail = t;
			eventail = &t->next;
		}
		isodd = !isodd;
	}
	*oddtail = even;
	*eventail = 0;
	return(odd);
}

main(){}
