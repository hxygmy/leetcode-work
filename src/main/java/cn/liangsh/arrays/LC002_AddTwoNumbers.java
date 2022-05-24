package cn.liangsh.arrays;

/**
 * @Description: 两数相加
 * @Author: Liangsh
 * @Date: 2022/5/24 22:42
 */
public class LC002_AddTwoNumbers {

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode flag = head;
        int value = 0;

        while (l1 != null || l2 != null) {
            int x = l1 == null ? 0 : l1.val;
            int y = l2 == null ? 0 : l2.val;
            int sum = x + y + value;
            // 进位值
            value = sum / 10;
            // 进位后的和
            sum = sum % 10;

            flag = new ListNode(sum);
            flag = flag.next;

            if (l1 != null) {
                l1 = l1.next;
            }

            if (l2 != null) {
                l2 = l2.next;
            }
        }

        // 最后一次进位
        if (value > 0) {
            flag.next = new ListNode(value);
        }

        return head.next;
    }

}

class ListNode {
    int val;
    ListNode next;

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
