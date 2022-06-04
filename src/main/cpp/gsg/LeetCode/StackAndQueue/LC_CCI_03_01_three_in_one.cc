// 学到了大量对此题无用的知识
// debug 经验++++++++++++++

// 还有
// 1. 二维数组解法（白给）
// 2. ！！重要 0 1 2 0 1 2 0 1 2 式 分配  太妙了!!!
// 失眠了或者明天再做
#include <tuple>
#include <vector>
#include <utility>

using std::get;
using std::pair;
using std::tuple;
using std::vector;

// 2. 同样是纪念 那坨 shit，简单清理了一下
class TripleInOne
{
public:
    TripleInOne(int stackSize)
        : tripleStack(stackSize * 3), stackMemo(3), capacity(stackSize)
    {
        // stackMemo[0].first = 0;
        stackMemo[1].first = capacity;
        stackMemo[2].first = capacity << 1;
    }

    void push(int stackNum, int value)
    {
        if (stackMemo[stackNum].second == capacity)
            return;
        tripleStack[stackMemo[stackNum].first + stackMemo[stackNum].second++] = value;
    }

    int pop(int stackNum)
    {
        if (stackMemo[stackNum].second == 0)
            return -1;
        return tripleStack[stackMemo[stackNum].first + --stackMemo[stackNum].second];
    }

    int peek(int stackNum)
    {
        if (stackMemo[stackNum].second == 0)
            return -1;
        return tripleStack[stackMemo[stackNum].first - 1 + stackMemo[stackNum].second];
    }

    bool isEmpty(int stackNum)
    {
        return stackMemo[stackNum].second == 0;
    }

private:
    vector<int> tripleStack;
    vector<pair<int, int>> stackMemo; // start_Index, size
    int capacity;
};

// 1. 纪念这坨让我学到很多东西的 shit
class TripleInOne
{
public:
    TripleInOne(int stackSize)
        : tripleStack(stackSize * 3), idxMemo(3), capacity(stackSize)
    {
        // idxMemo[1].first = 0;
        get<1>(idxMemo[0]) = 0;
        // get<2>(idxMemo[1]) = get<1>(idxMemo[1]) + stackSize - 1;

        get<1>(idxMemo[1]) = capacity;
        // get<2>(idxMemo[2]) = get<1>(idxMemo[2]) + stackSize - 1;

        get<1>(idxMemo[2]) = capacity * 2;
        // get<2>(idxMemo[3]) = get<1>(idxMemo[3]) + stackSize - 1;
        // cout << "[null,";
    }

    void push(int stackNum, int value)
    {
        if (get<0>(idxMemo[stackNum]) == capacity)
        {
            // cout << "null,";
            return;
        }
        tripleStack[get<1>(idxMemo[stackNum]) + get<0>(idxMemo[stackNum])++] = value;
        // cout << "null,";
    }

    int pop(int stackNum)
    {
        if (get<0>(idxMemo[stackNum]) == 0)
        {
            // cout << "-1,";
            return -1;
        }
        return tripleStack[--get<0>(idxMemo[stackNum]) + get<1>(idxMemo[stackNum])];
        // int ret = tripleStack[--get<0>(idxMemo[stackNum]) + get<1>(idxMemo[stackNum])];
        // cout << ret << ",";
        // return ret;
    }

    int peek(int stackNum)
    {
        if (get<0>(idxMemo[stackNum]) == 0)
        {
            // cout << "-1,";
            return -1;
        }
        return tripleStack[get<0>(idxMemo[stackNum]) - 1 + get<1>(idxMemo[stackNum])];
        // int ret = tripleStack[get<0>(idxMemo[stackNum]) - 1 + get<1>(idxMemo[stackNum])];
        // cout << ret << ",";
        // return ret;
    }

    bool isEmpty(int stackNum)
    {
        return get<0>(idxMemo[stackNum]) == 0;
        // int ret = (get<0>(idxMemo[stackNum]) == 0);
        // if (ret)
        // {
        // cout << "ture,";
        // }
        // else
        // {
        // cout << "false,";
        // }
        // return ret;
    }

private:
    vector<int> tripleStack;
    vector<tuple<int, int, int>> idxMemo; // size begin end
    int capacity;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */