package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description 构建最大二叉树
 * @date 2022/6/21 14:31
 */
public class LC654_ConstructMaximumBinaryTree {

    public TreeNode constructMaximumBinaryTree(int[] nums) {
        TreeNode root = new TreeNode();
        if (nums.length == 1) {
            root.val = nums[0];
            return root;
        }
        // 找出最大值下标
        int index = 0;
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        root.val = max;

        // 根据最大值划分区间
        if (index > 0) {
            int[] leftNums = new int[index];
            System.arraycopy(nums, 0, leftNums, 0, index);
            root.left = constructMaximumBinaryTree(leftNums);
        }

        if (index < nums.length - 1) {
            int[] rightNums = new int[nums.length - index - 1];
            System.arraycopy(nums, index + 1, rightNums, 0, nums.length - index - 1);
            root.right = constructMaximumBinaryTree(rightNums);
        }
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
