/*
 * Created by hexiaoyu 
 * on 2023/2/26 13:59
 * https://leetcode.cn/problems/repeated-substring-pattern/
 * easy
 */
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        int sub_size = 0;

        // next数组
        vector<int> pi(size);

        for(int i = 1, j = 0; i < size; i++){
            while(j > 0 and s[i] != s[j]){
                j = pi[j - 1];
            }
            if(s[i] == s[j]) {
                j++;
            }
            if(j == 1 or j <= pi[i - 1]) sub_size = i - j + 1;
            pi[i] = j;
        }
        return sub_size != 0
           and pi[size - 1] != 0
           and pi[size - 1] % sub_size == 0;
    }
};

int main(){
    Solution *a = new Solution();
    string s = "abaababaab";
    a->repeatedSubstringPattern(s);
    return 0;
}
