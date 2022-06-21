package cn.liangsh.tree;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Liangsh
 * @description 路径总和
 * @date 2022/6/21 14:35
 */
public class LC113_PathSum {

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        if (root == null) {
            return result;
        }

        traversal(root, targetSum, result, path);

        return result;
    }

    private void traversal(TreeNode root, int targetSum, List<List<Integer>> result, List<Integer> path) {
        path.add(root.val);
        if (root.left == null && root.right == null) {
            // 找到路径
            if (targetSum - root.val == 0) {
                result.add(new ArrayList<>(path));
            }

            return;
        }

        if (root.left != null) {
            traversal(root.left, targetSum - root.val, result, path);
            // 回溯
            path.remove(path.size() - 1);
        }

        if (root.right != null) {
            traversal(root.right, targetSum - root.val, result, path);
            path.remove(path.size() - 1);
        }
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
