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
#include "iostream"

using namespace std;

template <typename K, typename V>
struct MyNode {
    K key;
    V value;
    MyNode *pre;
    MyNode *next;
    MyNode() : key(0), value(0), pre(nullptr), next(nullptr) {}
    ~MyNode() = default;
    MyNode(K _key, V _value) : key(_key), value(_value), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:

    unordered_map<int, MyNode<int, int>*> map;
    MyNode<int, int> *head, *tail;
    int capacity;
    int size;

    explicit LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new MyNode<int, int>();
        tail = new MyNode<int, int>();
        head->next = tail;
        head->pre = tail;
        tail->pre = head;
        tail->next = head;
    }

    int get(int key) {
        if (map.find(key) != map.end()) {
            int res = map[key]->value;
            changeToTail(map[key]);
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        // 先找是不是已经存在
        if (map.find(key) != map.end()) {
            map[key]->value = value;
            changeToTail(map[key]);
            return;
        }
        auto *node = new MyNode<int, int> (key, value);

        if (capacity == size) {
            pop_front();
            size--;
        }
        addAtTail(node);
        map[key] = node;
        size++;
    }

    void pop_front() {
        MyNode<int, int> *p = head->next;
        head->next = p->next;
        p->next->pre = head;
        map.erase(map.find(p->key));
        delete p;
    }
    void addAtTail(MyNode<int, int> *node) const {
        node->pre = tail->pre;
        node->next = tail;
        tail->pre->next = node;
        tail->pre = node;
    }
    void changeToTail(MyNode<int, int> *node) const {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        addAtTail(node);
    }

};

int main () {
    auto *p = new LRUCache(2);
    p->put(1, 1);
    p->put(2, 2);
    int i = p->get(1);
    cout << i << "\t";
    p->put(3, 3);
    i = p->get(2);
    cout << i << "\t";
    p->put(4, 4);
    i = p->get(1);
    cout << i << "\t";

    i = p->get(3);
    cout << i << "\t";

    i = p->get(4);
    cout << i << "\t";

    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
