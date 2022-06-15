package cn.liangsh.tree;

/**
 * @author Liangsh
 * @description 构建二叉树
 * @date 2022/6/15 13:44
 */
public class LC103_BuildTree {

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length == 0 || postorder.length == 0) {
            return null;
        }

        // 获取当前节点值,为后序数组最后一个元素
        int rootVal = postorder[postorder.length - 1];
        TreeNode root = new TreeNode(rootVal);

        // 根据后序根节点划分中序数组
        int index = 0;
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == rootVal) {
                index = i;
                break;
            }
        }

        // 中序划分，左闭右开
        int[] leftInorder = new int[index];
        // index为真实长度的前一位
        int[] rightInorder = new int[inorder.length - index - 1];
        System.arraycopy(inorder, 0, leftInorder, 0, index);
        // 排除index的元素
        System.arraycopy(inorder, index + 1, rightInorder, 0, inorder.length - index - 1);

        // 后序数组长度和中序相同
        int[] leftPostorder = new int[index];
        int[] rightPostorder = new int[inorder.length - index - 1];
        // 排除最后一位元素
        System.arraycopy(postorder, 0, leftPostorder, 0, index);
        System.arraycopy(postorder, index, rightPostorder, 0, inorder.length - index - 1);

        root.left = buildTree(leftInorder, leftPostorder);
        root.right = buildTree(rightInorder, rightPostorder);

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
