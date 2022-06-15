package cn.liangsh.tree;

import cn.liangsh.node.TreeNode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * @author Liangsh
 * @description 二叉树右视图
 * @date 2022/6/15 11:46
 */
public class LC199_RightSideView {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);
        System.out.println(new LC199_RightSideView().rightSideView(root));
    }

    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        List<Integer> result = new ArrayList<>();

        // 递归
        recursion(result, root, 0);

        // 迭代
//        iteration(root, result);

        return result;
    }

    private void recursion(List<Integer> result, TreeNode root, int deep) {
        if (root == null) {
            return;
        }

        // 当前深度下result没有被添加元素，则是右视图第一个元素 如: deep = 0, result.size = 0
        if (deep == result.size()) {
            result.add(root.val);
        }

        deep++;
        // 从右往左遍历
        recursion(result, root.right, deep);
        recursion(result, root.left, deep);
    }

    private void iteration(TreeNode root, List<Integer> result) {
        Deque<TreeNode> deque = new ArrayDeque<>();
        deque.offer(root);

        while (!deque.isEmpty()) {
            int size = deque.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = deque.poll();
                if (node.left != null) {
                    deque.offer(node.left);
                }
                if (node.right != null) {
                    deque.offer(node.right);
                }
                // 最后一条数据加入列表
                if (i == size - 1) {
                    result.add(node.val);
                }
            }
        }
    }
}
