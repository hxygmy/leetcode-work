package cn.hxy.medium;

import cn.hxy.Test.ListNode;
import org.junit.Test;

/**
 * 2. 两数相加
 * <p>
 * 给你两个非空 的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
 * <p>
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * <p>
 * 你可以假设除了数字 0 之外，这两个数都不会以 0开头。
 * <p>
 * 
 * <p>
 * 示例 1：
 * <p>
 * <p>
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 示例 2：
 * <p>
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 示例 3：
 * <p>
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * <p>
 * 提示：
 * <p>
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
 *
 * <a href="https://leetcode.cn/problems/add-two-numbers">链接</a>
 *
 * @author 何晓宇
 * 2022/5/24 16:35
 */
public class LC0002 {

     /**
      * 两数之和，其实就是竖式计算
      * 1. 建立一个头结点和一个指向头结点的指针，使后续操作具有一致性
      * 2. 当两个链表都有孩子时，指针向后移动，是l1.val + l2.val + flag（flag即进位问题，见下）
      * 3. 由于存在满10进1的规则，定义一个flag来确定是否存在进位，当l1.val + l2.val + flag > 10则需要进位，否则不需要
      * 4. 当存在已经遍历完的链表时，剩余部分只需要另一个链表的节点.val + flag即可，直到两个链表都遍历结束
      *
      * @param l1   链表1
      * @param l2   链表2
      * @return     相加后的链表
      */
     public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
          ListNode buffer = new ListNode(0);
          ListNode result = buffer;

          int flag = 0;
          while (l1 != null && l2 != null){
               buffer.next = new ListNode(0);
               buffer = buffer.next;
               int i = l1.val + l2.val + flag;
               buffer.val = i % 10;
               flag = i / 10;
               l1 = l1.next;
               l2 = l2.next;
          }

          while (l1 != null){
               buffer.next = new ListNode(0);
               buffer = buffer.next;
               int i = flag + l1.val;
               buffer.val = i % 10;
               flag = i / 10;
               if(flag == 0){
                    buffer.next = l1.next;
                    break;
               } else {
                    l1 = l1.next;
               }
          }

          while (l2 != null){
               buffer.next = new ListNode(0);
               buffer = buffer.next;
               int i = flag + l2.val;
               buffer.val = i % 10;
               flag = i / 10;
               if(flag == 0){
                    buffer.next = l2.next;
                    break;
               } else {
                    l2 = l2.next;
               }
          }

          if(flag == 1){
               buffer.next = new ListNode(1);
          }

          return result.next;
     }



     @Test
     public void test(){
          ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(4)));
          ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
          System.out.println(addTwoNumbers(l1, l2));
     }


     /*
      *执行用时：
      * 1 ms
      * , 在所有 Java 提交中击败了
      * 100.00%
      * 的用户
      * 内存消耗：
      * 41.3 MB
      * , 在所有 Java 提交中击败了
      * 61.92%
      * 的用户
      * 通过测试用例：
      * 1568 / 1568
      */

}
