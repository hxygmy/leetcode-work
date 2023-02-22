/*
 * Created by hexiaoyu 
 * on 2023/2/23 1:58
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/
 * medium
 */
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};

        int left = 0, right = 0;

        vector<int> compara1(26);
        vector<int> compara2(26);

        for(char c : p){
            compara1[c - 'a']++;
        }

        while(right < p.size()){
            compara2[s[right] - 'a']++;
            right++;
        }
        right--;
        vector<int> res;
        if(compara1 == compara2) res.emplace_back(left);

        while(right < s.size() - 1){
            compara2[s[left] - 'a']--;
            left++;
            right++;
            compara2[s[right] - 'a']++;
            if(compara1 == compara2) res.emplace_back(left);
        }

        return res;
    }
};


int main(){
    string s = "cbaebabacd";
    string p = "abc";
    Solution *a = new Solution();
    auto b = a->findAnagrams(s, p);
    return 0;
}
