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
        if(index < 0 and index >= this->size) return -1;

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
        if (index <= 0) addAtHead(val);
        if (index > this->size) return;
        MyLinkedNode *p = head;
        while(index > 0 and p->next){
            p = p->next;
            index--;
        }
        p->next = new MyLinkedNode(val);
        this->size++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 or index >= this->size) return;
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
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->get(1);
    obj->deleteAtIndex(1);
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
