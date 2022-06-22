package cn.liangsh.tree;

import cn.liangsh.node.TreeNode;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * @author Liangsh
 * @description 中序后继
 * @date 2022/6/22 15:56
 */
public class MS0406_InorderSuccessor {

    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        if (root == null || p == null) {
            return null;
        }

        // 中序遍历,左中右
//        return recursion(root, p);

        return iteration(root, p);
    }

    private TreeNode iteration(TreeNode root, TreeNode p) {
        TreeNode flag = null;
        TreeNode pre = root;

        Deque<TreeNode> stack = new ArrayDeque<>();
        while (!stack.isEmpty() || pre != null) {
            if (pre != null) {
                stack.push(pre);
                pre = pre.left;
            } else {
                pre = stack.pop();
                // 上一个节点是p
                if (flag == p) {
                    return pre;
                }
                flag = pre;
                pre = pre.right;
            }
        }

        return null;
    }

    private TreeNode recursion(TreeNode root, TreeNode p) {
        if (root == null) {
            return null;
        }

        recursion(root.left, p);
        if (root == p) {

        }
        recursion(root.right, p);

        return null;
    }
}
