package cn.liangsh.tree;

import java.util.*;

/**
 * @author Liangsh
 * @description 层序遍历II
 * @date 2022/6/6 13:56
 */
public class LC107_LevelOrder2 {

    class TreeNode {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode next;

        public TreeNode() {
        }

        public TreeNode(int val) {
            this.val = val;
        }

        public TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public List<List<Integer>> levelOrderII(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        List<List<Integer>> result = new ArrayList<>();

        // 递归
        recursion(root, result, 0);

        // 迭代
//        iteration(root, result);

        Collections.reverse(result);
        return result;
    }

    private void recursion(TreeNode root, List<List<Integer>> result, int deep) {
        if (root == null) {
            return;
        }
        deep++;

        // 加入对应层级容量的List
        if (result.size() < deep) {
            List<Integer> item = new ArrayList<>();
            result.add(item);
        }
        result.get(deep - 1).add(root.val);
        recursion(root.left, result, deep);
        recursion(root.right, result, deep);
    }

    private void iteration(TreeNode root, List<List<Integer>> result) {
        Deque<TreeNode> deque = new ArrayDeque<>();
        deque.offer(root);
        while (!deque.isEmpty()) {
            // 当前层
            int size = deque.size();
            List<Integer> level = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                TreeNode node = deque.poll();
                level.add(node.val);

                if (node.left != null) {
                    deque.offer(node.left);
                }
                if (node.right != null) {
                    deque.offer(node.right);
                }
            }
            result.add(level);
        }
    }
}
