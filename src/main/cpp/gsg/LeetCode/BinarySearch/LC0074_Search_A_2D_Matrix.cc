#include <vector>

using std::vector;

// 3. 二分搜索出所在行，再二分搜索（合理）

// 这个应该是这道题出题的题意了，暂时没有写，饿了
// 打算还是先写从 最右列 二分搜索所在行，再基本二分搜索
// 我这猪脑咋就想不到呢，看到 1.5年 前写的乌龟爬才反应过来

// 2. 乌龟爬 （下次再来，只利用特性）
//
// 从右上角或左下角乌龟爬应该都是可以的（只写了右上角）
// 突出一个题目特性的利用
// 自上至下遍历矩阵最右侧元素，不比 target 小了就停止，说明 target 如果存在的话一定在这一行，再遍历即可得到答案。如果最后一个元素还没有 target 大，那就自然没有这个元素了
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int right = matrix[0].size() - 1;
        int row = 0;
        while (row < matrix.size())
        {
            if (target <= matrix[row][right])
                break;
            ++row;
        }
        if (row >= matrix.size())
            return false;
        while (right >= 0)
        {
            if (target == matrix[row][right--])
                return true;
        }
        return false;
    }
};

// 1. 坐标映射 二分查找 （下次再来，未利用特性）
//
// 映射为线性，转换成自己熟悉的一位数组二分查找
// 当前写的解决方法是 写 getVal 函数，从 矩阵取值
// 二分查找部分几乎完全相同，只是通过 getVal 取值
// 坐标映射：
// row = index / matrix[0].size()
// col = index % matrix[0].size()
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        return binarySearch(matrix, 0, matrix.size() * matrix[0].size() - 1, target);
    }

private:
    bool binarySearch(vector<vector<int>> &matrix, int low, int high, int target)
    {
        if (low > high)
            return false;
        int mid = low + (high - low) / 2;
        int val = getVal(matrix, mid);
        if (val < target)
            return binarySearch(matrix, mid + 1, high, target);
        if (val > target)
            return binarySearch(matrix, low, mid - 1, target);
        return true;
    }

    int getVal(vector<vector<int>> &matrix, int index)
    {
        int row = index / matrix[0].size();
        int col = index % matrix[0].size();
        return matrix[row][col];
    }
};