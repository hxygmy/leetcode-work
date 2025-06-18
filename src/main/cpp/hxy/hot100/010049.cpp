#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<pmr::string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string str : strs) {
            int counts[26] = {0};
            for(char c : str) {
                counts[c - 'a']++;
            }
            string key = "";
            for(int i = 0; i < 26; i++) {
                if(counts[i] != 0) {
                    key.push_back(i + 'a');
                    key.push_back(counts[i]);
                }
            }
            map[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto& p : map) {
            res.push_back(p.second);
        }
        return res;
    }
};
