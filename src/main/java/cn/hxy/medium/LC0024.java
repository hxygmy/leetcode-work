package cn.hxy.medium;

import cn.hxy.Test.ListNode;

/**
 * 24. 两两交换链表中的节点
 *
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 *
 *  
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 * 示例 2：
 *
 * 输入：head = []
 * 输出：[]
 * 示例 3：
 *
 * 输入：head = [1]
 * 输出：[1]
 *  
 *
 * 提示：
 *
 * 链表中节点的数目在范围 [0, 100] 内
 * 0 <= Node.val <= 100
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/swap-nodes-in-pairs
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 * @author Applewald
 * 2022/6/17 16:37
 */
public class LC0024 {
	public static void main(String[] args) {

	}

	public ListNode swapPairs(ListNode head) {
		if (head == null){
			return null;
		}
		if (head.next == null){
			return head;
		}
		ListNode pair = head;
		ListNode res = head.next;
		ListNode tmp = null;
		while (pair != null && pair.next != null) {

			if (tmp != null) tmp.next.next = pair.next;
			tmp = pair.next;
			pair.next = tmp.next;
			tmp.next = pair;
			pair = pair.next;
		}
		return res;
	}


	/*
	 * 执行用时：
	 * 0 ms
	 * , 在所有 Java 提交中击败了
	 * 100.00%
	 * 的用户
	 * 内存消耗：
	 * 39 MB
	 * , 在所有 Java 提交中击败了
	 * 59.63%
	 * 的用户
	 * 通过测试用例：
	 * 55 / 55
	 */
}
