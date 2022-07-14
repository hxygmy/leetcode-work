package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description 修剪二叉树
 * @date 2022/6/30 8:41
 */
public class LC669_TrimBST {

    public TreeNode trimBST(TreeNode root, int low, int high) {
        if (root == null) {
            return null;
        }

        // 左子树节点比区间小，返回其右子树
        if (root.val < low) {
            return trimBST(root.right, low, high);
        }

        // 右子树节点比区间打，返回其左子树
        if (root.val > high) {
            return trimBST(root.left, low, high);
        }

        // 根节点
        root.left = trimBST(root.left, low, high);
        root.right = trimBST(root.right, low, high);
        return root;
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
