/*
 * Created by hexiaoyu 
 * on 2023/2/21 23:13
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
 * medium
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode *res = new ListNode(0, head);
        // 双指针
        ListNode *left = res, *right = res;

        for(int i = 0; i < n; i++) {
            right = right->next;
        }
        while(right->next){
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
        return res->next;
    }
};