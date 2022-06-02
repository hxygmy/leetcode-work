package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description 最小深度
 * @date 2022/6/2 9:30
 */
public class LC111_MinDepth {

    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        // 后序遍历
        int left = minDepth(root.left);
        int right = minDepth(root.right);

        // 左子树为空，右子树不为空，不是叶子节点
        if (root.left == null && root.right != null) {
            return 1 + right;
        }

        // 左子树不为空，右子树为空，不是叶子节点
        if (root.left != null && root.right == null) {
            return 1 + left;
        }

        int depth = 1 + Math.min(left, right);

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
