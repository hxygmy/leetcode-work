/*
 * Created by hexiaoyu 
 * on 2023/3/13 17:46
 */
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<char>> map = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
    };

    vector<string> res;
    string path;

    // 递归函数的参数和返回类型
    void recursive(string digits, int seq){
        if(digits.size() == seq){
            res.push_back(path);
            return;
        }

        for(char c: map[digits[seq] - '2']){
            path.push_back(c);
            recursive(digits, seq + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        recursive(digits, 0);
        return res;
    }
};