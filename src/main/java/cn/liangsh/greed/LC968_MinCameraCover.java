package cn.liangsh.greed;


/**
 * @author Liangsh
 * @description 监控二叉树
 * @date 2022/9/6 11:19
 */
public class LC968_MinCameraCover {

    private int result;

    public int minCameraCover(TreeNode root) {
        result = 0;

        // 根节点无覆盖
        if (traversal(root) == 0) {
            result++;
        }

        return result;
    }

    private int traversal(TreeNode root) {
        if (root == null) {
            // 空节点有覆盖
            return 2;
        }

        // 后序遍历，左右中
        int left = traversal(root.left);
        int right = traversal(root.right);

        // 左右孩子存在无覆盖的节点
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }

        // 左右孩子存在摄像头
        if (left == 1 || right == 1) {
            return 2;
        }

        // 左右节点都有覆盖
        if (left == 2 && right == 2) {
            return 0;
        }

        return -1;
    }


    private class TreeNode {
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
