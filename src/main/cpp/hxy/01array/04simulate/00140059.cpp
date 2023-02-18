/*
 * Created by hexiaoyu 
 * on 2023/2/18 13:36
 * https://leetcode.cn/problems/spiral-matrix-ii/
 * medium
 */

#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 1) return {{1}};

        vector<vector<int>> res(n, vector<int>(n));

        int i = 0;
        int j = i;
        int begin = 0;
        int end = n - 1;

        int k = 1;

        while (k < n * n) {
            while(j < end) {
                res[i][j] = k++;
                j++;
            }
            while(i < end) {
                res[i][j] = k++;
                i++;
            }
            while(j > begin) {
                res[i][j] = k++;
                j--;
            }
            begin++;
            while(i > begin) {
                res[i][j] = k++;
                i--;
            }
            end--;
        }
        res[i][j] = n * n;
        return res;
    }
};