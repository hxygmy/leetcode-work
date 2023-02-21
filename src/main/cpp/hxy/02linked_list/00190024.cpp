/*
 * Created by hexiaoyu 
 * on 2023/2/21 22:56
 * https://leetcode.cn/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        ListNode *res = new ListNode(0, head);

        // 前驱指针
        ListNode *pre = res;

        // 指向两个需要交换的节点
        ListNode *fir, *sec;

        // 后继指针
        ListNode *last;

        while(pre->next) {

            // 把指针放好
            fir = pre->next;
            sec = fir->next;
            if(!sec) break;
            last = sec->next;

            // 换位置
            pre->next = sec;
            fir->next = last;
            sec->next = fir;

            // 下一轮迭代
            pre = fir;
        }
        return res->next;
    }
};
