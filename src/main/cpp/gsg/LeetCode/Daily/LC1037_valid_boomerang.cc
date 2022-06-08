#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib> // std_abs.h included
#include <cmath>   // std_abs.h included

using std::abs;  // <cmath> <cstdlib> both including std_abs.h which defined abs()
using std::swap; // <utility> since C++11, <algorithm> until C++11
using std::vector;

// 3. 摘自 官解 评论区
// @像云～ mark 一下，感觉十分清晰易理解，但我仍然看不懂，日后再看
// https://leetcode.cn/u/xiang-yun-h5/
//利用前两个点组成直线，判断第三个点在不在直线上就好了，超越100%
// class Solution {
//    public boolean isBoomerang(int[][] points) {
//        //抽离三个点坐标
//        int x1=points[0][0],y1=points[0][1];
//        int x2=points[1][0],y2=points[1][1];
//        int x3=points[2][0],y3=points[2][1];
//        //判断三个点是否各不相同
//        if(x1==x2&&y1==y2 || x1==x3&&y1==y3 ||x2==x3&&y2==y3)
//            return false;
//        //用前两个点确定直线方程，判断第三个点在不在这条直线上
//        else{
//            //两点确定直线方程满足AX+BY+C=0
//            int A,B,C;
//            A=y1-y2;
//            B=x2-x1;
//            C=x1*y2-x2*y1;
//            //若第三个点满足直线方程，说明三点一线，不满足
//            if((A*x3+B*y3+C)==0)
//                return false;
//            else
//                return true;
//        }
//    }
//}

// 2. 共三点，两点构成执行斜率相等则为一条直线
class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &points)
    {
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];

        if ((x1 - x2) * (y1 - y3) == (x1 - x3) * (y1 - y2))
            return false;
        return true;
    }
};

// 1. shit 超大份
// 唯一可能的有记录价值的地方是没有用浮点数？？？
class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &points)
    {
        int x1 = points[0][0];
        int y1 = points[0][1];
        int x2 = points[1][0];
        int y2 = points[1][1];
        int x3 = points[2][0];
        int y3 = points[2][1];

        int diffX = x1 - x2;
        int diffY = y1 - y2;

        if (diffX == 0 && diffY == 0 || x1 == x3 && y1 == y3 || x2 == x3 && y2 == y3)
            return false;
        if (diffX == 0 && x1 == x3)
            return false;
        if (diffY == 0 && y1 == y3)
            return false;

        if (x3 < x1)
        { // 使 x1点 x1为 较小， x3点 x3为较大
            swap(x3, x1);
            swap(y3, y1);
        }

        if (diffX < 0)
        {
            diffX = -diffX;
            diffY = -diffY;
        }
        if (diffX == 0)
            diffY = abs(diffY);
        if (diffY == 0)
            diffX = abs(diffX);

        if (diffX != 0 && diffY != 0)
        {
            for (int i = 2; i <= 100; i++)
            { // 15, -6  --> / 3 -- > 5, -2
                while (diffX % i == 0 && diffY % i == 0)
                {
                    diffX /= i;
                    diffY /= i;
                }
            }
        }

        if (diffY > 0 && y1 > y3)
            return true;
        if (diffY < 0 && y1 < y3)
            return true;

        bool yOver = y1 <= y3;
        while (x1 <= x3)
        {
            x1 += diffX;
            y1 += diffY;
            if (x1 == x3 && y1 == y3)
                return false;
            if ((y1 <= y3) != yOver)
                return true;
        }
        return true;
    }
};