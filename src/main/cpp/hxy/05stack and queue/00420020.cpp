/*
 * Created by hexiaoyu 
 * on 2023/2/26 16:02
 * https://leetcode.cn/problems/valid-parentheses/
 * easy
 */
#include "string"
#include "stack"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> in;

        for (char c: s) {
            if (c == '[' or c == '{' or c == '(') {
                in.push(c);
            } else {
                if (!in.empty()
                    and (
                            (c == '}' and in.top() == '{')
                         or (c == ']' and in.top() == '[')
                         or (c == ')' and in.top() == '(')
                    )
                ) {
                    in.pop();
                } else {
                    return false;
                }
            }
        }
        return in.empty();
    }
};
