package cn.liangsh.node;

/**
 * @author Liangsh
 * @description 链表
 * @date 2022/5/24 8:49
 */
public class ListNode {
    public int val;
    public ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
