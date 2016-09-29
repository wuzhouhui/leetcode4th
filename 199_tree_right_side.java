import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        LinkedList<Integer> res = new LinkedList<>();
        LinkedList<TreeNode> q1 = new LinkedList<>();
        LinkedList<TreeNode> q2 = new LinkedList<>();
        if (root == null)
            return res;
        q1.addLast(root);
        while (q1.size() > 0) {
            res.addLast(q1.getLast().val);
            while (q1.size() > 0) {
                TreeNode node = q1.pollFirst();
                if (node.left != null)
                    q2.addLast(node.left);
                if (node.right != null)
                    q2.addLast(node.right);
            }
            LinkedList<TreeNode> tmp = q1;
            q1 = q2;
            q2 = tmp;
        }
        return res;
    }
}
