/*
 * Created by hexiaoyu 
 * on 2023/3/1 15:40
 * https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/
 * easy
 */
#include "vector"
#include "queue"

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<Node*> que;

        que.emplace(root);

        Node* p;
        int this_level = 1;
        int next_level = 0;
        int res = 1;

        while(!que.empty()){
            p = que.front();
            que.pop();
            this_level--;

            for(Node* n :p->children){
                if(n){
                    que.emplace(n);
                    next_level++;
                }
            }

            if(this_level == 0){
                if(next_level > 0){
                    res++;
                }
                this_level = next_level;
                next_level = 0;
            }
        }
        return res;
    }
};
