package cn.hxy.Test;


import cn.hxy.medium.LC0002;

/**
 * @author Applewald
 * 2022/6/27 10:19
 */
public class ListNode {
	public int val;
	public ListNode next;

	public ListNode() {

	}
	public ListNode(int val) {
		this.val = val;
	}
	public ListNode(int val, ListNode next) {
		this.val = val;
		this.next = next;
	}

	@Override
	public String toString() {
		return next == null ? val + "" : val + "," + next;
	}
}
