/*
 * Created by hexiaoyu 
 * on 2023/2/18 22:24
 * https://leetcode.cn/problems/design-linked-list/
 * medium
 */
struct MyLinkedNode{
    int val;
    MyLinkedNode *next;

    MyLinkedNode(){
        this->val = 0;
        this->next = nullptr;
    };
    explicit MyLinkedNode(int val){
        this->val = val;
        this->next = nullptr;
    };
    MyLinkedNode(int val, MyLinkedNode *next){
        this->val = val;
        this->next = next;
    }
};

class MyLinkedList {

    MyLinkedNode *head;
    int size;

public:

    MyLinkedList() {
        this->head = new MyLinkedNode();
        this->size = 0;
    }

    int get(int index) {
        if(index < 0 or index >= this->size) {
            return -1;
        }

        MyLinkedNode *p = head;
        while(index > 0){
            p = p->next;
            index--;
        }
        return p->next->val;
    }

    void addAtHead(int val) {
        this->head->next = new MyLinkedNode(val, this->head->next);
        this->size++;
    }

    void addAtTail(int val) {
        MyLinkedNode *p = head;
        while(p->next){
            p = p->next;
        }
        p->next = new MyLinkedNode(val);
        this->size++;
    }

    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (index == this->size) {
            addAtTail(val);
            return;
        }
        if (index > this->size) return;

        MyLinkedNode *p = head;
        while(index > 0){
            p = p->next;
            index--;
        }
        p->next = new MyLinkedNode(val, p->next);
        this->size++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 or index >= this->size){
            return;
        }
        MyLinkedNode *p = head;
        while (index > 0){
            p = p->next;
            index--;
        }
        p->next = p->next->next;
        size--;
    }
};

int main(){
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(7);
    obj->addAtHead(2);
    obj->addAtHead(1);
    obj->addAtIndex(3, 0);
    obj->deleteAtIndex(2);
    obj->addAtHead(6);
    obj->addAtTail(4);
    obj->get(4);
    obj->addAtHead(4);
    obj->addAtIndex(5, 0);
    obj->addAtHead(6);
    return 0;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
