package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description 删除二叉搜素树的节点
 * @date 2022/6/24 8:52
 */
public class LC450_DeleteNode {

    public static void main(String[] args) {
//        [5,3,6,2,4,null,7]

        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.right = new TreeNode(6);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(4);
        root.right.right = new TreeNode(7);

//        System.out.println(new LC450_DeleteNode().deleteNode(new TreeNode(0), 0));

    }

    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            // 根节点为空
            return root;
        }
        if (root.val == key) {
            if (root.left == null && root.right == null) {
                // 叶子节点
                return null;
            }

            if (root.left == null && root.right != null) {
                // 左子树为空，右子树不为空
                return root.right;
            }

            if (root.left != null && root.right == null) {
                // 右子树为空，左子树不为空
                return root.left;
            }

            // 左右子树均不为空,将右子树的最左节点设置为根节点的子树，替换右子树为根节点
            TreeNode cur = root.right;
            while (cur.left != null) {
                cur = cur.left;
            }
            cur.left = root.left;
            return root.right;
        }

        if (root.val > key) {
            // 需要返回值接收
            root.left = deleteNode(root.left, key);
        }

        if (root.val < key) {
            // 需要返回值接收
            root.right = deleteNode(root.right, key);
        }

        return root;
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
