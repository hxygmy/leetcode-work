/*
 * Created by hexiaoyu 
 * on 2023/3/18 2:33
 * https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
 * easy
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& A, int k) {
        sort(A.begin(), A.end(), cmp);
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < 0 && k > 0) {
                A[i] *= -1;
                k--;
            }
        }
        if (k % 2 == 1) A[A.size() - 1] *= -1;
        int result = 0;
        for (int a : A) result += a;
        return result;
    }
};
