import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {

    private LinkedList<List<Integer>> res;
    private LinkedList<Integer> path;

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        res = new LinkedList<>();
        path = new LinkedList<>();
        do_sum(root, sum);
        return res;
    }

    private void do_sum(TreeNode root, int sum) {
        if (root == null)
            return;
        path.addLast(root.val);
        sum -= root.val;
        if (root.left == null && root.right == null && sum == 0) {
            List<Integer> apath = new LinkedList<>(path);
            res.add(apath);
            path.removeLast();
            return;
        }
        do_sum(root.left, sum);
        do_sum(root.right, sum);
        path.removeLast();
        return;
    }
}
