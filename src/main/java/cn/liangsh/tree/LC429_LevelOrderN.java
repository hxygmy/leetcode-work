package cn.liangsh.tree;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * @author Liangsh
 * @description
 * @date 2022/6/15 11:48
 */
public class LC429_LevelOrderN {

    public List<List<Integer>> levelOrder(Node root) {
        if (root == null) {
            return new ArrayList<>();
        }

        List<List<Integer>> result = new ArrayList<>();

        // 递归
        recursion(root, result, 0);

        // 迭代
        iteration(root, result);

        return result;
    }

    private void recursion(Node root, List<List<Integer>> result, int depth) {
        if (root == null) {
            return;
        }

        List<Integer> level = new ArrayList<>();
        List<Node> children = root.children;


    }

    private void iteration(Node root, List<List<Integer>> result) {
        Deque<Node> deque = new ArrayDeque<>();
        deque.offer(root);

        while (!deque.isEmpty()) {
            int size = deque.size();
            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                Node poll = deque.poll();
                // 子树入队
                List<Node> children = poll.children;
                for (int j = 0; j < children.size(); j++) {
                    deque.offer(children.get(j));
                }

                level.add(poll.val);
            }
            result.add(level);
        }
    }

    class Node {

        public int val;
        public List<Node> children;

        public Node() {
        }

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }

    }
}
