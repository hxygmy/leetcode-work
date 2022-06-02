package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description 二叉树对称
 * @date 2022/6/2 9:30
 */
public class LC101_IsSymmetric {
    public boolean isSymmetric(TreeNode root) {

        return symmetricChect(root.left, root.right);
    }

    private boolean symmetricChect(TreeNode left, TreeNode right) {
        // 采用外侧、内侧的方式使用后序遍历
        if (left != null && right == null) return false;
        if (left == null && right != null) return false;
        if (left == null && right == null) return true;
        if (left.val != right.val) return false;

        // 外侧，左节点的左子树，右节点的右子树
        boolean outside = symmetricChect(left.left, right.right);
        // 外侧，左节点的右子树，右节点的左子树
        boolean inside = symmetricChect(left.right, right.left);

        return outside && inside;
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
