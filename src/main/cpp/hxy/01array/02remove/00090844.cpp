/*
 * Created by hexiaoyu 
 * on 2023/2/14 6:25
 * https://leetcode.cn/problems/backspace-string-compare/
 * easy
 */
#include "string"

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        // skip计数器
        int s_skip = 0, t_skip = 0;
        int sp = s.length() - 1, tp = t.length() - 1;

        while(sp >= 0 or tp >= 0){
            while (sp >= 0) {
                if(s[sp] == '#') {
                    s_skip++;
                    sp--;
                } else if (s_skip > 0) {
                    s_skip--;
                    sp--;
                } else {
                    break;
                }
            }

            while (tp >= 0) {
                if(t[tp] == '#') {
                    t_skip++;
                    tp--;
                } else if(t_skip > 0) {
                    t_skip--;
                    tp--;
                } else {
                    break;
                }
            }

            if (sp >= 0 and tp >= 0) {
                if (s[sp] != t[tp]) {
                    return false;
                } else {
                    sp--;
                    tp--;
                }
            } else {
                if (sp >= 0 or tp >= 0){
                    return false;
                } else {
                    return true;
                }
            }

        }

        return true;
    }
};

int main(){
    string s = "ab##";
    string t = "c#d#";
    Solution *a = new Solution();
    bool b = a->backspaceCompare(s, t);
    return b;
}
