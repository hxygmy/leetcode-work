/*
 * Created by hexiaoyu 
 * on 2023/2/23 14:59
 * https://leetcode.cn/problems/intersection-of-two-arrays/
 * easy
 */
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res = {};

        int i = 0, j = 0;
        while(i < nums1.size() and j < nums2.size()) {
            while(i + 1 < nums1.size() and nums1[i] == nums1[i + 1]) {
                i++;
            }
            while(j + 1 < nums2.size() and nums2[j] == nums2[j + 1]) {
                j++;
            }
            if(nums1[i] == nums2[j]){
                res.emplace_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums1 = {4,7,9,7,6,7};
    vector<int> nums2 = {5,0,0,6,1,6,2,2,4};
    Solution *a = new Solution();
    auto b = a->intersection(nums1, nums2);
    return 0;
}
