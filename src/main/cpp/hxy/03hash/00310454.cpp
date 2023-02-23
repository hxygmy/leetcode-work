/*
 * Created by hexiaoyu 
 * on 2023/2/23 18:37
 * https://leetcode.cn/problems/4sum-ii/
 * medium
 */
#include "unordered_map"
#include "vector"

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> group1;

        int res = 0;

        for(int i : nums1){
            for(int j : nums2) {
                group1[i + j]++;
            }
        }

        for(int i : nums3){
            for(int j : nums4){
                if(group1.find(-i-j) != group1.end()){
                    res += group1[-i-j];
                }
            }
        }
        return res;
    }
};
