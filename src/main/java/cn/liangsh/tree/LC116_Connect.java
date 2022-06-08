package cn.liangsh.tree;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * @author Liangsh
 * @description 填充每个节点的下一个右侧节点指针
 * @date 2022/6/8 8:43
 */
public class LC116_Connect {

    public PerfectNode connect(PerfectNode root) {
        if (root == null) {
            return null;
        }

        Deque<PerfectNode> deque = new ArrayDeque<>();
        deque.offer(root);

        // 按照层序遍历，给每一层后续添加指针
        while (!deque.isEmpty()) {
            int size = deque.size();

            for (int i = 0; i < size; i++) {
                PerfectNode poll = deque.poll();

                if (i != size - 1) {
                    poll.next = deque.peek();
                }

                if (poll.left != null) {
                    deque.offer(poll.left);
                }

                if (poll.right != null) {
                    deque.offer(poll.right);
                }
            }
        }

        return root;
    }

    class PerfectNode {

        public int val;
        public PerfectNode left;
        public PerfectNode right;
        public PerfectNode next;

        public PerfectNode() {
        }

        public PerfectNode(int _val) {
            val = _val;
        }

        public PerfectNode(int _val, PerfectNode _left, PerfectNode _right, PerfectNode _next) {
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }

    }
}
