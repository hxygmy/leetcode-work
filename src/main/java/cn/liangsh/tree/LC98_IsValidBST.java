package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description 验证二叉搜索树
 * @date 2022/6/21 14:31
 */
public class LC98_IsValidBST {
    TreeNode max;

    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        // 中序遍历，结果从小到大
        boolean left = isValidBST(root.left);

        if (max != null && root.val <= max.val) {
            return false;
        }
        max = root;

        boolean right = isValidBST(root.right);

        return left && right;
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
