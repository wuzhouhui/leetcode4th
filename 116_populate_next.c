struct TreeLinkNode {
	int	val;
	struct TreeLinkNode *left, *right, *next;
};

void connect(struct TreeLinkNode *root)
{
	if (root == 0)
		return;

	struct TreeLinkNode *upper, *cur, *p1, *p2;

	root->next = 0;
	upper = root;
	cur = root->left;
	while (cur) {
		p1 = cur;
		while (1) {
			p2 = upper;
			upper = upper->next;
			p1->next = p2->right;
			p1 = p1->next;
			if (upper) {
				p1->next = upper->left;
				p1 = p1->next;
			} else {
				p1->next = 0;
				break;
			}
		}
		upper = cur;
		cur = cur->left;
	}
}
main(){}
