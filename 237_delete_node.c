struct ListNode {
	int	val;
	struct ListNode *next;
};

void deleteNode(struct ListNode *node)
{
	struct ListNode *p = node->next;
	node->val = p->val;
	node->next = p->next;
}
main(){}
