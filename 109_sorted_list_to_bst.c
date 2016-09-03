#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *sortedListToBST(struct ListNode *head)
{
	if (head == NULL)
		return(NULL);
	struct TreeNode *node = malloc(sizeof(*node));
	if (head->next == NULL) {
		node->val = head->val;
		node->left = node->right = NULL;
		return(node);
	}
	struct ListNode **mid = &head;
	struct ListNode *two = head->next;
	while (two->next) {
		mid = &(*mid)->next;
		two = two->next;
		two = two->next;
		if (two == NULL)
			break;
	}
	node->val = (*mid)->val;
	node->right = sortedListToBST((*mid)->next);
	*mid = NULL;
	node->left = sortedListToBST(head);
	return(node);
}
main()
{
	struct ListNode head = { 0, 0 };
	struct TreeNode *root = sortedListToBST(&head);
}
