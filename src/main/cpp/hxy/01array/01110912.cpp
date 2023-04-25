/*
 * Created by hexiaoyu
 * on 2023/4/15 0:15
 * https://leetcode.cn/problems/sort-an-array
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> sortArrayQuickSort(vector<int>& nums) {
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
        // 随机取中值
        int ra = rand() % (high - low + 1) + low;
        int pivot = nums[ra];
        nums[ra] = nums[low];
        nums[low] = pivot;

        int len;
        int cycle;

        while (low < high) {
            len = high - low + 1;
            cycle = 0;
            while (low < high && nums[high] >= pivot && cycle < len / 2) {
                high--;
                cycle++;
            }
            while (low < high && nums[high] > pivot) {
                high--;
            }
            nums[low] = nums[high];

            len = high - low + 1;
            cycle = 0;
            while (low < high && nums[low] <= pivot && cycle < len / 2) {
                low++;
                cycle++;
            }
            while (low < high && nums[low] < pivot) {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }

    // 归并排序
    vector<int> sortArrayMergeSort(vector<int>& nums) {
        size = nums.size();
        tmp.resize(size);
        mergeSort(nums, 0, size - 1);
        return nums;
    }

    int size;
    vector<int> tmp;
    void merge(vector<int> &nums, int low, int mid, int high) {
        for(int i = low; i <= high; i++){
            tmp[i] = nums[i];
        }
        int i, j, k;
        for(i = low, j = mid + 1, k = i; i <= mid && j <= high; k++){
            if(tmp[i] <= tmp[j]){
                nums[k] = tmp[i++];
            } else {
                nums[k] = tmp[j++];
            }
        }
        while(i <= mid){
            nums[k++] = tmp[i++];
        }
        while(j <= high){
            nums[k++] = tmp[j++];
        }
    }

    void mergeSort(vector<int> &nums, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }

    // 堆排序
    vector<int> sortArrayHeapSort(vector<int>& nums) {
        heapSort(nums, nums.size());
        return nums;
    }

    /**
     * 把以k为根的子树调整为大根堆
     * @param k 数组下标
     * @param n 数组长度
     */
    void headAdjust(vector<int> &nums, int k, int n) {
        int tmp = nums[k];
        for (int i = 2 * k + 1; i < n; i = 2 * i + 1) {
            if (i < n - 1 && nums[i] < nums[i + 1]) {
                i++;
            }
            if (tmp < nums[i]) {
                nums[k] = nums[i];
                k = i;
            } else {
                break;
            }
        }
        nums[k] = tmp;
    }

    void heapSort(vector<int> &nums, int n) {
        for (int i = n / 2; i >= 0; i--) {
            headAdjust(nums, i, n);
        }

        int swap;
        for (int i = n - 1; i >= 0; i--) {
            swap = nums[i];
            nums[i] = nums[0];
            nums[0] = swap;

            headAdjust(nums, 0, i);
        }
    }
};

int main(){
    vector<int> x = {5,1,1,2,0,0};
    Solution *a = new Solution();
    a->sortArrayHeapSort(x);
    int c = 0;
    return c;
}
