/*
 * Created by hexiaoyu 
 * on 2023/2/12 17:33
 * https://leetcode.cn/problems/sqrtx/
 * 简单
 */
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        if (x < 4) {
            return 1;
        }
        int left = 0;
        int right = x;
        while (left < right) {
            int mid = (left + right) / 2;
            int sq = x / mid;
            if (sq > mid) {
                left = mid + 1;
            } else if (sq == mid) {
                return mid;
            } else {
                right = mid - 1;
            }
        }
        if (left * left <= x) {
            return left;
        } else {
            return left - 1;
        }
    }
};

int main(){
    int x = 8;
    Solution *a = new Solution();
    int b = a->mySqrt(x);
    return b;
}
