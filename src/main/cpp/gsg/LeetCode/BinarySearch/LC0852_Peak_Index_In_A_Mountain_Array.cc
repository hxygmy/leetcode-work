// 解 一 过鲁棒，可应对各种情况，可作为模板（写的还是很不错的）
// 解 二 三 ：特解

#include <vector>

using std::vector;

// 3. 聪明递归笨二分
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        return binarySearch(arr, 1, arr.size() - 2);
    }

    int binarySearch(vector<int> &arr, int left, int right)
    {
        int mid = left + (right - left) / 2;
        int midVal = arr[mid];

        if (midVal > arr[mid - 1])
        {
            if (midVal > arr[mid + 1])
            {
                return mid;
            }
            return binarySearch(arr, mid + 1, right);
        }
        return binarySearch(arr, left, mid - 1);
    }
};

// 2. 聪明迭代笨二分
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 1;
        int right = arr.size() - 2;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int midVal = arr[mid];
            if (midVal > arr[mid - 1])
            {
                if (midVal > arr[mid + 1])
                {
                    return mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                right = mid - 1;
            }
        }

        return 0x12345678;
    }
};

// 1. 递归笨二分，为什么这么慢，因为这样写二分太傻了
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        return binarySearchPeak(arr, 0, arr.size() - 1);
    }

    int binarySearchPeak(vector<int> &arr, int left, int right)
    {
        if (left > right)
            return -1;
        int mid = left + (right - left) / 2;
        if (mid == 0)
            return binarySearchPeak(arr, mid + 1, right);
        if (mid == arr.size() - 1)
            return binarySearchPeak(arr, left, mid - 1);
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        if (arr[mid] > arr[mid - 1])
            return binarySearchPeak(arr, mid + 1, right);
        return binarySearchPeak(arr, left, mid - 1);
    }
};