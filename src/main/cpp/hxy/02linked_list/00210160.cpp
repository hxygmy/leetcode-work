/*
 * Created by hexiaoyu 
 * on 2023/2/21 23:38
 * https://leetcode.cn/problems/intersection-of-two-linked-lists/
 * easy
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a != b){
            a = a? a->next : headB;
            b = b? b->next : headA;
        }
        return a;
    }
};
