package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description 二叉搜索树转为累加树
 * @date 2022/6/30 10:44
 */
public class LC538_ConvertBST {
    int pre = 0;

    public TreeNode convertBST(TreeNode root) {
        if (root == null) {
            return null;
        }


        // 反中序遍历
        root.right = convertBST(root.right);
        // 记录前一节点的数值
        root.val += pre;
        pre = root.val;
        root.left = convertBST(root.left);
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
