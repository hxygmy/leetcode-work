package com.liangsh.tree.preorder;

/**
 * @author Liangsh
 * @description 二叉搜索树的最近公共祖先
 * @date 2022/6/23 8:49
 */
public class LC235_LowestCommonAncestor {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return root;
        }

        // 根节点较大，往左子树遍历
        if (root.val > p.val && root.val > q.val) {
            TreeNode left = lowestCommonAncestor(root.left, p, q);
            if (left != null) {
                return left;
            }
        }

        // 根节点较小，往右子树遍历
        if (root.val < p.val && root.val < q.val) {
            TreeNode right = lowestCommonAncestor(root.right, p, q);
            if (right != null ) {
                return right;
            }
        }

        return root;
    }

    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }
}
