/*
 * Created by hexiaoyu 
 * on 2023/2/26 15:37
 * https://leetcode.cn/problems/implement-stack-using-queues/
 */
#include "queue"

using namespace std;

class MyStack {
public:
    queue<int> in;

    MyStack() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if(empty()) {
            return -1;
        } else {
            for(int i = 0; i < in.size() - 1; i++){
                in.push(in.front());
                in.pop();
            }
        }
        int res = in.front();
        in.pop();
        return res;
    }

    int top() {
        int res = pop();
        in.push(res);
        return res;
    }

    bool empty() {
        return in.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
