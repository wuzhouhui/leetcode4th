#ifndef bool
#define bool int
#endif

struct ListNode {
	int	val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
	if (!head)
		return(0);

	struct ListNode *step1 = head;
	struct ListNode *step2 = head->next;

	while (step2 && step2 != step1) {
		step1 = step1->next;
		step2 = step2->next;
		if (step2)
			step2 = step2->next;
	}
	return(step2 != 0);
}
main(){}
