//
// Created by hexy on 25-6-18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, h = 0, res = 0, s = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                h = height[left];
                left++;
            } else {
                h = height[right];
                right--;
            }
            s = (right - left + 1) * h;
            if (res < s) res = s;
        }
        return res;
    }
};