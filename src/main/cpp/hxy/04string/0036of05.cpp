/*
 * Created by hexiaoyu 
 * on 2023/2/25 2:05
 * https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
 * easy
 */
#include "string"

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        if(s.size() == 0) return "";

        // 计算有几个空格
        int num = 0;
        for(char c : s){
            if(c == ' ') {
                num++;
            }
        }

        int left = s.size() - 1;
        s.resize(s.size() + 2 * num);
        int right = s.size() - 1;

        while(left < right){
            if(s[left] == ' '){
                s[right--] = '0';
                s[right--] = '2';
                s[right--] = '%';
                left--;
            } else {
                s[right--] = s[left--];
            }
        }

        return s;
    }
};

int main(){
    string s = "We are happy.";
    Solution *a = new Solution();
    a->replaceSpace(s);
    return 0;
}