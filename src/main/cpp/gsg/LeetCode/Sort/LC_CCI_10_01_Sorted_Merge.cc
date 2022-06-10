#include <vector>

using std::vector;

// 2. 逆向双指针 开脑洞
// 小的就该呆那里不动，如果足够大，不该呆那，在赋值到那之前就已经到自己新家了
// 这里对应着 1.正向双指针 三个 while 的 单 while 写法
class Solution
{
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n)
    {
        int pa = m - 1;
        int pb = n - 1;
        int curLast = m + n - 1;
        while (pa >= 0 || pb >= 0)
        {
            if (pa < 0)
                A[curLast--] = B[pb--];
            else if (pb < 0)
                A[curLast--] = A[pa--];
            else
                A[curLast--] = A[pa] >= B[pb] ? A[pa--] : B[pb--];
        }
    }
};

// 1. 正向双指针，需要一个 m + n 的临时vector<int>
// O(M+N), O(M+N)
//可以一个while完成
//可以用一个变量接收值，最后再赋值，提高可读性
class Solution
{
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n)
    {
        vector<int> sorted(m + n);
        int idxS = 0;
        int idxA = 0;
        int idxB = 0;
        while (idxA < m && idxB < n)
            sorted[idxS++] = A[idxA] <= B[idxB] ? A[idxA++] : B[idxB++];
        while (idxA != m)
            sorted[idxS++] = A[idxA++];
        while (idxB != n)
            sorted[idxS++] = B[idxB++];
        A = sorted;
    }
};