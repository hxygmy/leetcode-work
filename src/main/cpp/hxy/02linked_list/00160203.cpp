/*
 * Created by hexiaoyu 
 * on 2023/2/18 15:53
 * https://leetcode.cn/problems/remove-linked-list-elements/
 * easy
 */
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode *res = head;
        while(res->val == val and res->next){
            res = res->next;
        }
        if(res->val == val) return nullptr;
        ListNode *tmp = res;
        while(tmp and tmp->next){
            while(tmp->next->val == val){
                if(tmp->next->next) {
                    tmp->next = tmp->next->next;
                } else {
                    tmp->next = nullptr;
                    break;
                }
            }
            tmp = tmp->next;
        }
        return res;
    }
};
