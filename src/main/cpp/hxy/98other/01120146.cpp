/*
 * Created by hexiaoyu
 * on 2023/5/5 0:15
 * https://leetcode.cn/problems/lru-cache/
 * medium
 */
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "list"

using namespace std;

template <typename K, typename V>
struct MyNode {
    K key;
    V value;
    MyNode *pre;
    MyNode *next;
    MyNode() : key(0), value(0), pre(nullptr), next(nullptr) {}
    MyNode(K _key, V _value) : key(_key), value(_value), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:

    unordered_map<int, MyNode<int, int>*> map;
    MyNode<int, int> *head, *tail;
    int capacity;
    int size;

    LRUCache(int capacity) : capacity(capacity) {
        head->next = tail;
        head->pre = tail;
        tail->pre = head;
        tail->next = head;
    }

    int get(int key) {
        if (order.f)
        if (map.find(key) != map.end()) {
            map[key].second++;
            return map[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        // 先找是不是已经存在
        if (map.find(key) != map.end()) {

        }
        if (map.size() < size) {
            MyNode<int, int> *node = new MyNode<int, int> (key, value);
            addAtTail(node);
            map[key] = node;
        } else {

        }
    }

    void addAtTail(MyNode<int, int> *node) {
        node->pre = tail->pre;
        node->next = tail;
        tail->pre->next = node;
        tail->pre = node;
    }
    void changeToTail(MyNode<int, int> *node) {
        MyNode<int, int> *p = node->pre;
        p->next = node->next;
        node->next->pre = p;
        addAtTail(node);
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
