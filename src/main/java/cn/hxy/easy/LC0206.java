package cn.hxy.easy;

/**
 * 206. 反转链表
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 *  
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
 * 示例 3：
 *
 * 输入：head = []
 * 输出：[]
 *  
 *
 * 提示：
 *
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 <= Node.val <= 5000
 *  
 *
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/reverse-linked-list
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author Applewald
 * 2022/6/16 12:11
 */
public class LC0206 {
	public static void main(String[] args) {

	}

	public ListNode reverseList(ListNode head) {
		if (head == null) {
			return null;
		}
		if (head.next == null) {
			return head;
		}
		if (head.next.next == null){
			head.next.next = head;
			ListNode res = head.next;
			head.next = null;
			return res;
		}
		ListNode begin;
		ListNode mid;
		ListNode end;
		begin = head;
		mid = head.next;
		end = mid.next;

		// 断第一个指针
		head.next = null;

		while (end != null) {
			mid.next = begin;
			begin = mid;
			mid = end;
			end = end.next;
		}
		mid.next = begin;
		return mid;
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
			 this.val = val; this.next = next;
		 }
	 }

}
