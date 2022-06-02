package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description 最大深度
 * @date 2022/6/2 9:29
 */
public class LC104_MaxDepth {

    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int right = maxDepth(root.left);
        int left = maxDepth(root.right);
        int depth = 1 + Math.max(left, right);

        return depth;
    }

    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}
