//
// Created by hexy on 25-6-18.
//
#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                n++;
            } else if (n != 0) {
                nums[i - n] = nums[i];
                nums[i] = 0;
            }
        }
    }
};

int main() {
    vector<int> nums = {0,1,0,3,12};
    Solution *s = new Solution();
    s->moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }
    return 0;
}
