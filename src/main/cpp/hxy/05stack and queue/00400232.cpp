/*
 * Created by hexiaoyu 
 * on 2023/2/26 15:17
 * https://leetcode.cn/problems/implement-queue-using-stacks/
 * easy
 */
#include "stack"

using namespace std;

class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        int p = peek();
        if (p != -1) out.pop();
        return p;
    }

    int peek() {
        if(empty()){
            return -1;
        } else if (out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool empty() {
        return in.empty() and out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
