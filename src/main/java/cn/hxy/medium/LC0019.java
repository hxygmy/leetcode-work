package cn.hxy.medium;

import cn.hxy.Test.ListNode;

/**
 * 19. 删除链表的倒数第 N 个结点
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 *  
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 示例 2：
 *
 * 输入：head = [1], n = 1
 * 输出：[]
 * 示例 3：
 *
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 *  
 *
 * 提示：
 *
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author Applewald
 * 2022/6/27 10:18
 */
public class LC0019 {
	public static void main(String[] args) {

	}
	public ListNode removeNthFromEnd(ListNode head, int n) {

		int size = 0;
		ListNode p = head;
		while(p != null) {
			size++;
			p = p.next;
		}

		if (size == n) return head.next;

		int piv = size - n;
		p = head;
		for (int i = 1; i < piv; i++) {
			p = p.next;
		}

		p.next = p.next == null? null: p.next.next;
		return head;
	}
}
