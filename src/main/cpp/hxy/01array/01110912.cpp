/*
 * Created by hexiaoyu
 * on 2023/4/15 0:15
 * https://leetcode.cn/problems/sort-an-array
 * medium
 */
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int low, int high) {
        if (low < high) {
            int pivotpos = partition(nums, low, high);
            quickSort(nums, low, pivotpos - 1);
            quickSort(nums, pivotpos + 1, high);
        }
    }

    int partition(vector<int> &nums, int low, int high) {
        int mid = (low + high) / 2;
        int pivot = nums[mid];
        nums[mid] = nums[low];
        nums[low] = pivot;
        while (low < high) {
            while (low < high && nums[high] >= pivot) {
                high--;
            }
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot) {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
};

int main(){
    vector<int> x = {5,1,1,2,0,0};
    Solution *a = new Solution();
    a->sortArray(x);
    int c = 0;
    return c;
}
