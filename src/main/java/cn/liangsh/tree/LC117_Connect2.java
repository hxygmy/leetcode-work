package cn.liangsh.tree;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * @Description: 填充每个节点的下一个右侧节点指针 II
 * @Author: Liangsh
 * @Date: 2022/5/25 22:46
 */
public class LC117_Connect2 {


    public Node connect(Node root) {
        if (root == null) {
            return null;
        }

        Deque<Node> deque = new ArrayDeque<>();
        deque.offer(root);

        while (!deque.isEmpty()) {
            int size = deque.size();

            // 层序遍历
            for (int i = 0; i < size; i++) {
                Node poll = deque.poll();

                if (poll.left != null) {
                    deque.offer(poll.left);
                }

                if (poll.right != null) {
                    deque.offer(poll.right);
                }

                // 将next指向下一个节点
                if (i != size - 1) {
                    poll.next = deque.peek();
                }
            }
        }


        return root;
    }

}

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
}
