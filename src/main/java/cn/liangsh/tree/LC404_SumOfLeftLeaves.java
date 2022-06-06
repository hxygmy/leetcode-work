package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description
 * @date 2022/6/6 13:53
 */
public class LC404_SumOfLeftLeaves {
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

    public int sumOfLeftLeaves(TreeNode treeNode) {
        if (treeNode == null) {
            return 0;
        }

        // 后序遍历左右中
        int left = sumOfLeftLeaves(treeNode.left);
        int right = sumOfLeftLeaves(treeNode.right);
        int mid = 0;
        if (treeNode.left != null && treeNode.left.left == null && treeNode.left.right == null) {
            // 左叶子节点，左右孩子为空，从父节点判断
            mid = treeNode.left.val;
        }

        int sum = mid + right + left;

        return sum;
    }
}
