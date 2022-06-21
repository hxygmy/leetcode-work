package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description 二叉树建树 先序
 * @date 2022/6/15 17:02
 */
public class LC105_BuildTreeII {

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (inorder.length == 0 || preorder.length == 0) {
            return null;
        }

        int rootVal = preorder[0];
        TreeNode root = new TreeNode(rootVal);
        int index = 0;
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == rootVal) {
                index = i;
                break;
            }
        }

        int[] leftInorder = new int[index];
        int[] rightInorder = new int[inorder.length - index - 1];
        System.arraycopy(inorder, 0, leftInorder, 0, index);
        System.arraycopy(inorder, index + 1, rightInorder, 0, inorder.length - index - 1);

        int[] leftPreorder = new int[index];
        int[] rightPreorder = new int[inorder.length - index - 1];
        System.arraycopy(preorder, 1, leftPreorder, 0, index);
        System.arraycopy(preorder, index + 1, rightPreorder, 0, inorder.length - index - 1);

        root.left = buildTree(leftPreorder, leftInorder);
        root.right = buildTree(rightPreorder, rightInorder);

        return root;
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
