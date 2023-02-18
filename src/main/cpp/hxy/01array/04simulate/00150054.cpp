/*
 * Created by hexiaoyu 
 * on 2023/2/18 15:05
 * https://leetcode.cn/problems/spiral-matrix/
 * medium
 */
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();

        int i = 0, j = 0;
        vector<int> res(m * n);

        int begin = 0;
        int end_m = m - 1;
        int end_n = n - 1;

        int k = 0;

        while(k < m * n - 1){
            while(j < end_n and k < m * n - 1) {
                res[k++] = matrix[i][j++];
            }
            end_n--;
            while(i < end_m and k < m * n - 1) {
                res[k++] = matrix[i++][j];
            }
            end_m--;

            while(j > begin and k < m * n - 1) {
                res[k++] = matrix[i][j--];
            }
            begin++;
            while(i > begin and k < m * n - 1){
                res[k++] = matrix[i--][j];
            }
        }
        res[k] = matrix[i][j];
        return res;
    }
};

int main(){
    vector<vector<int>> n = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution *a = new Solution();
    auto b = a->spiralOrder(n);
    return 0;
}