package cn.liangsh.tree;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * @author Liangsh
 * @description 层序平均值
 * @date 2022/6/2 9:31
 */
public class LC637_AverageOfLevels {

    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new ArrayList<>();

        Deque<TreeNode> deque = new ArrayDeque<>();
        deque.offer(root);

        while (!deque.isEmpty()) {
            double size = deque.size();
            double sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode treeNode = deque.poll();
                if (treeNode.left != null) {
                    deque.offer(treeNode.left);
                }
                if (treeNode.right != null) {
                    deque.offer(treeNode.right);
                }
                sum += treeNode.val;
            }

            res.add(sum / size);
        }

        return res;
    }

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
}
