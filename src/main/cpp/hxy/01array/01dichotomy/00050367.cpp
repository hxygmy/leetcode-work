/*
 * Created by hexiaoyu 
 * on 2023/2/14 5:23
 * https://leetcode.cn/problems/valid-perfect-square/
 * easy
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        int left = 0;
        int right = num;
        while (left < right) {
            int mid = (left + right) / 2;
            int sq = num / mid;
            if (sq > mid) {
                left = mid + 1;
            } else if (sq == mid) {
                left = mid;
                break;
            } else {
                right = mid - 1;
            }
        }
        if (left * left == num || (left - 1) * (left - 1) == num){
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    int num = 5;
    Solution *a = new Solution();
    bool b = a->isPerfectSquare(num);
    return b;
}
