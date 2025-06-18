//
// Created by hexy on 25-6-17.
//
#include "vector"
#include "unordered_set"

using namespace std;
class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;

        for (int &i : nums) {
            nums_set.emplace(i);
        }

        int res = 0;

        for (int i : nums_set) {
            if (!nums_set.count(i - 1)) {
                int length = 1;

                while (nums_set.count(i + 1)) {
                    length++;
                    i++;
                }

                res = length > res ? length : res;
            }
        }

        return res;
    }
};
