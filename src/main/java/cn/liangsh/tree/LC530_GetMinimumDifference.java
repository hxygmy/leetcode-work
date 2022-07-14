package cn.liangsh.tree;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * @author Liangsh
 * @description 二叉搜索树的绝对最小差
 * @date 2022/6/22 15:55
 */
public class LC530_GetMinimumDifference {

    public int getMinimumDifference(TreeNode root) {
        if (root == null) {
            return Integer.MAX_VALUE;
        }
        int res = Integer.MAX_VALUE;

        TreeNode pre = null;

        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode cur = root;

        while (cur != null || !stack.isEmpty()) {
            // 中序遍历
            if (cur != null) {
                // 左节点入栈
                stack.push(cur);
                cur = cur.left;
            } else {
                cur = stack.pop();
                if (pre != null) {
                    res = Math.min(cur.val - pre.val, res);
                }
                pre = cur;
                cur = cur.right;
            }

        }

        return res;
    }

    static class TreeNode {
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
