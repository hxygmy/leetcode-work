/*
 * Created by hexiaoyu 
 * on 2023/2/17 15:46
 * https://leetcode.cn/problems/fruit-into-baskets/
 * medium
 */

#include "vector"

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() == 0) return 0;
        if(fruits.size() == 1) return 1;
        // 慢指针，开始位置
        int left = 0;
        // 当前数组中有的元素
        int e1 = fruits[left], e2;
        // 当前可采摘数量
        int sum1 = 1;
        int sum2 = 0;
        bool full = false;
        // 当前最多可采摘数量
        int res = 0;
        // i 为快指针，结束位置
        for (int i = 1; i < fruits.size(); i++) {
            while (!full and i < fruits.size()) {
                if (fruits[i] == e1){
                    sum1++;
                    i++;
                } else {
                    e2 = fruits[i];
                    full = true;
                    sum2++;
                    i++;
                }
            }
            while(i < fruits.size() and (fruits[i] == e1 or fruits[i] == e2)) {
                if (i < fruits.size() and fruits[i] == e1) {
                    sum1++;
                    i++;
                }
                if (i < fruits.size() and fruits[i] == e2) {
                    sum2++;
                    i++;
                }
            }

            if (sum1 + sum2 > res) {
                res = sum1 + sum2;
            }

            if (i < fruits.size()) {
                if(e1 == fruits[i - 1]) {
                    while (sum2 > 0) {
                        if (fruits[left] == e2) {
                            left++;
                            sum2--;
                        } else {
                            left++;
                            sum1--;
                        }
                    }
                    e2 = fruits[i];
                    sum2++;
                } else {
                    while (sum1 > 0) {
                        if (fruits[left] == e1) {
                            left++;
                            sum1--;
                        } else {
                            left++;
                            sum2--;
                        }
                    }
                    e1 = fruits[i];
                    sum1++;
                }
            }
        }
        return res;
    }
};
int main(){
    vector<int> fruits = {1,0,1,4,1,4,1,2,3};
    Solution *a = new Solution();
    int b = a->totalFruit(fruits);
    return b;
}