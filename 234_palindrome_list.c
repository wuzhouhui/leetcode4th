#ifndef bool
#define bool int
#endif

struct ListNode {
	int	val;
	struct ListNode *next;
};

bool isPalindrome(struct ListNode *head)
{
	if (!head || !head->next)
		return(1);

	int c, i, res;
	struct ListNode *after, *p, *t;

	for (c = 0, p = head; p; p = p->next)
		c++;
	for (p = head, i = 1; i < c / 2; i++)
		p = p->next;
	if (c % 2)
		p = p->next;
	after = 0;
	t = p->next;
	p->next = 0;
	while (t) {
		p = t;
		t = t->next;
		p->next = after;
		after = p;
	}
	t = after;
	p = head;
	res = 1;
	while (p && t) {
		if (p->val != t->val)
			res = 0;
		p = p->next;
		t = t->next;
	}
	t = after;
	after = 0;
	while (t) {
		p = t;
		t = t->next;
		p->next = after;
		after = p;
	}
	while (head->next)
		head = head->next;
	while (after) {
		p = after;
		after = after->next;
		head->next = p;
		head = p;
	}
	return(res);
}

int main(void)
{
	struct ListNode n1 = { 1, 0 };
	struct ListNode n2 = { 0, &n1 };
	isPalindrome(&n2);
}
