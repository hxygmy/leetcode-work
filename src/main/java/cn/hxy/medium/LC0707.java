package cn.hxy.medium;


/**
 *707. 设计链表
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val和next。val是当前节点的值，next是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性prev以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
 *
 * 在链表类中实现这些功能：
 *
 * get(index)：获取链表中第index个节点的值。如果索引无效，则返回-1。
 * addAtHead(val)：在链表的第一个元素之前添加一个值为val的节点。插入后，新节点将成为链表的第一个节点。
 * addAtTail(val)：将值为val 的节点追加到链表的最后一个元素。
 * addAtIndex(index,val)：在链表中的第index个节点之前添加值为val 的节点。如果index等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 * deleteAtIndex(index)：如果索引index 有效，则删除链表中的第index 个节点。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/design-linked-list
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * @author Applewald
 * 2022/6/15 18:31
 */
public class LC0707 {

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
}



