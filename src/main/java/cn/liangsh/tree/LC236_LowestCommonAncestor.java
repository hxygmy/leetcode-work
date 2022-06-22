package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description 二叉树的公共祖先
 * @date 2022/6/22 15:54
 */
public class LC236_LowestCommonAncestor {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) {
            return root;
        }

        // 后序遍历
        root.left = lowestCommonAncestor(root.left, p, q);
        root.right = lowestCommonAncestor(root.right, p, q);

        // 左右子树均不为空，则root为最近祖先
        if( root.left != null && root.right != null) {
            return root;
        }

        // 左子树不为空，右子树为空则返回左子树，反之亦然
        if (root.left != null) {
            return root.left;
        }
        if (root.right != null) {
            return root.right;
        }
        return null;

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
