#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static char *buf;
static int buflen, maxbuflen, sum;

static void do_sum(const struct TreeNode *root)
{
	if (!root)
		return;
	if (buflen >= maxbuflen) {
		maxbuflen += 8;
		buf = realloc(buf, maxbuflen * sizeof(*buf));
	}
	buf[buflen++] = root->val + '0';
	if (root->left == NULL && root->right == NULL) {
		buf[buflen] = 0;
		sum += atoi(buf);
		buflen--;
		return;
	}
	do_sum(root->left);
	do_sum(root->right);
	buflen--;
}

int sumNumber(struct TreeNode *root)
{
	buflen = maxbuflen = sum = 0;
	buf = NULL;
	do_sum(root);
	if (buf)
		free(buf);
	return(sum);
}

main(){}
