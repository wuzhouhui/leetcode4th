import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {

    private List<String> paths;

    private void do_path(TreeNode root, StringBuffer pathbuffer) {
        if (root == null)
            return;
        int start = pathbuffer.length();
        if (start == 0)
            pathbuffer.append(root.val);
        else
            pathbuffer.append("->" + root.val);
        if (root.left == null && root.right == null)
            paths.add(pathbuffer.toString());
        else {
            do_path(root.left, pathbuffer);
            do_path(root.right, pathbuffer);
        }
        pathbuffer.delete(start, pathbuffer.length());
    }

    public List<String> binaryTreePaths(TreeNode root) {
        StringBuffer pathbuffer = new StringBuffer();
        paths = new LinkedList<>();
        do_path(root, pathbuffer);
        return paths;
    }
}
