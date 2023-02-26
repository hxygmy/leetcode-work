/*
 * Created by hexiaoyu 
 * on 2023/2/26 16:34
 * https://leetcode.cn/problems/evaluate-reverse-polish-notation/
 * medium
 */
#include "string"
#include "vector"
#include "stack"
#include "algorithm"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> t;

        for(string s : tokens){
            if(s == "+" or s == "-" or s == "*" or s == "/"){
                cal(t, s);
            } else {
                t.push(::atoi(s.c_str()));
            }
        }

        return t.top();
    }

    bool cal(stack<int> &t, string s){
        if(t.size() < 2) return false;
        int a, b;
        b = t.top();
        t.pop();
        a = t.top();
        t.pop();

        if(s == "+"){
            t.push(a + b);
        } else if (s == "-") {
            t.push(a - b);
        } else if (s == "*") {
            t.push(a * b);
        } else if (s == "/") {
            t.push(a / b);
        }
        return true;
    }
};
