/*
 * Created by hexiaoyu 
 * on 2023/3/15 17:10
 * https://leetcode.cn/problems/reconstruct-itinerary/
 * hard
 */
#include "vector"
#include "algorithm"
#include "string"
#include "map"

using namespace std;

class Solution {
public:

    /*
     * res里一共有 tickets.size() + 1 个元素
     * 考虑一下树形结构
     * 第一轮，从tickets中选择一个from中包含有JFK的vector
     * 对to部分进行字典排序
     * 第二层孩子，在tickets中找到一个from为上一层to的vector
     * 同理第三层第四层，层数有限制
     */
    vector<string> res;
    vector<bool> bitmap;

    // 1. 确定递归函数的参数和返回类型
    void fi_bt(vector<vector<string>> &tickets, string from){
        // 2. 确定函数出口
        if(res.size() == tickets.size() + 1) return;

        // 3. 单层递归逻辑
        // 3.1 先找到tickets中包含上一层to的ticket
        map<string, int> ts;
        ts.clear();
        for(int i = 0; i < tickets.size(); i++){
            if(tickets[i][0] == from and !bitmap[i]){
                ts[tickets[i][1]] = i;
            }
        }
        // 3.2 对ts进行字典排序，用map已经自动排序了
        // 3.3 对ts遍历插入
        for(auto i = ts.begin(); i != ts.end(); i++){
            res.push_back(i->first);
            bitmap[i->second] = true;
            fi_bt(tickets, i->first);
            if(res.size() == tickets.size() + 1) return;
            res.pop_back();
            bitmap[i->second] = false;
        }
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        bitmap.resize(tickets.size());
        res.emplace_back("JFK");
        fi_bt(tickets, "JFK");
        return res;
    }
};
