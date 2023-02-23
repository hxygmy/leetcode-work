/*
 * Created by hexiaoyu 
 * on 2023/2/24 1:56
 * https://leetcode.cn/problems/reverse-string-ii/
 * easy
 */

#include "string"

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        char tmp;
        int left, right;
        for(int i = 0; i < s.size(); i += 2 * k){
            left = i;
            if(i + k - 1 < s.size()) {
                right = i + k - 1;
            } else {
                right = s.size() - 1;
            }
            while(left < right){
                tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                left++;
                right--;
            }
        }
        return s;
    }
};

int main(){
    string s = "abcdefg";
    int k = 2;
    Solution *a = new Solution();
    auto b = a->reverseStr(s, k);
    return 0;
}