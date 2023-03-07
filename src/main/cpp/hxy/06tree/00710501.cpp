/*
 * Created by hexiaoyu 
 * on 2023/3/7 22:46
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/
 * easy
 */

#include "queue"
#include "algorithm"
#include "string"
#include "stack"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *p = root;

        vector<pair<int, int>> record;
        pair<int, int> current = {0, 0};

        while(!st.empty() or p){
            if(p){
                st.emplace(p);
                p = p->left;
            } else {
                p = st.top();
                st.pop();

                // 处理逻辑
                if(current.first != p->val) {
                    if(current.second > 0) record.push_back(current);
                    current.first = p->val;
                    current.second = 0;
                }
                current.second++;

                p = p->right;
            }
        }
        record.push_back(current);
        vector<int> res;
        int most = 0;
        for(auto r : record){
            if(most < r.second) most = r.second;
        }
        for(auto r : record){
            if(r.second == most) res.push_back(r.first);
        }
        return res;
    }
};
