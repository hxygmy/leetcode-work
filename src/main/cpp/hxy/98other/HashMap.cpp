//
// Created by hexia on 2023/10/10.
//
#include <iostream>
#include "vector"
#include "list"

const int MAX_LENGTH = 10;

struct KVNode {
    int key;
    int value;
    KVNode(int key, int value) : key(key), value(value) {}
};

class HashMap {
private:
    std::vector<std::list<KVNode>> hashmap;
    static int hash (int key) {
        return key % MAX_LENGTH;
    }
public:
    HashMap() {
        hashmap.resize(MAX_LENGTH);
    }
    void insert (int key, int value) {
        int index = hash(key);
        for (KVNode &kv: hashmap[index]) {
            if (kv.key == key) {
                kv.value = value;
                return;
            }
        }
        hashmap[index].emplace_back(key, value);
    };

    void remove (int key) {
        int index = hash(key);
        hashmap[index].remove_if([key](const KVNode kv) {
            return kv.key == key;
        });
    }

    int get (int key) {
        int index = hash(key);
        for (KVNode kv : hashmap[index]) {
            if (kv.key == key) {
                return kv.value;
            }
        }
        return -1;
    }
};

int main () {
    HashMap map;
    map.insert(1,2);
    map.insert(3,4);

    std::cout << "已经插入了1，2和3，4" << std::endl;
    std::cout << "1: " << map.get(1) << std::endl;
    std::cout << "3: " << map.get(3) << std::endl;
    map.insert(3,5);
    std::cout << "插入了3，5" << std::endl;
    std::cout << "3: " << map.get(3) << std::endl;
    map.remove(3);
    std::cout << "删除了3" << std::endl;
    std::cout << "3: " << map.get(3) << std::endl;

    return 0;
}