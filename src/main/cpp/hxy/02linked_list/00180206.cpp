/*
 * Created by hexiaoyu 
 * on 2023/2/21 22:32
 * https://leetcode.cn/problems/reverse-linked-list/
 * easy
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *p = new ListNode(0, head);
        ListNode *tmp = p->next;
        ListNode *t = tmp->next;
        tmp->next = nullptr;
        while(t){
            tmp = t->next;
            t->next = p->next;
            p->next = t;
            t = tmp;
        }
        return p->next;
    }
};