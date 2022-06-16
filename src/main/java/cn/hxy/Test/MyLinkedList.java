package cn.hxy.Test;


/**
 * @author Applewald
 * 2022/6/16 10:31
 */
class MyLinkedNode {
	int val;
	MyLinkedNode next;
	MyLinkedNode pre;

	public MyLinkedNode() {

	}

	public MyLinkedNode(int val) {
		this.val = val;
	}

	public MyLinkedNode(int val, MyLinkedNode next, MyLinkedNode pre) {
		this.val = val;
		this.next = next;
		this.pre = pre;
	}
}

class MyLinkedList {

	MyLinkedNode head;
	int size;


	public MyLinkedList() {
		this.head = new MyLinkedNode();
		this.head.next = head;
		this.head.pre = head;
		this.size = 0;
	}

	public int get(int index) {
		if (index < 0 || index >= this.size) return -1;
		MyLinkedNode f = head;
		for (int i = 0; i <= index; i++) {
			f = f.next;
		}
		return f.val;
	}

	public void addAtHead(int val) {
		MyLinkedNode newNode = new MyLinkedNode(val, head.next, head);
		this.head.next.pre = newNode;
		this.head.next = newNode;
		this.size++;
	}

	public void addAtTail(int val) {
		MyLinkedNode newNode = new MyLinkedNode(val, head, head.pre);
		this.head.pre.next = newNode;
		this.head.pre = newNode;
		this.size++;
	}

	public void addAtIndex(int index, int val) {
		if (index <= 0) {
			addAtHead(val);
			return;
		}
		if (index > size) {
			return;
		}
		if (index == size) {
			addAtTail(val);
			return;
		}
		MyLinkedNode f = new MyLinkedNode(val);
		MyLinkedNode h = this.head;
		for (int i = 0; i < index; i++) {
			h = h.next;
		}

		f.pre = h;
		f.next = h.next;
		h.next.pre = f;
		h.next = f;
		this.size++;
	}

	public void deleteAtIndex(int index) {
		if (index < 0 || index >= size) {
			return;
		}
		MyLinkedNode h = this.head;
		for (int i = 0; i <= index; i++) {
			h = h.next;
		}
		h.pre.next = h.next;
		h.next.pre = h.pre;
		this.size--;
	}
}
