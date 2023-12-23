#pragma once
using namespace std;
class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };
private:
    LinkedNode* _dummyHead;
    int _size;
public:
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    int get(int index) {
        if (_size < 1 || index < 0 || index >= _size)
            return -1;
        LinkedNode* p = _dummyHead;
        while (index >= 0) {
            p = p->next;
            index--;
        }
        return p->val;
    }

    void addAtHead(int val) {
        LinkedNode* p = new LinkedNode(val);
        p->next = _dummyHead->next;
        _dummyHead->next = p;
        _size++;
    }

    void addAtTail(int val) {
        LinkedNode* p = _dummyHead;
        while (p->next)
            p = p->next;
        p->next = new LinkedNode(val);
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > _size)
            return;
        else if (index == 0)
            addAtHead(val);
        else if (index == (_size))
            addAtTail(val);
        else {
            LinkedNode* p = _dummyHead;
            while (index--) {
                p = p->next;
                //index--;
            }
            LinkedNode* tmp = p->next;
            p->next = new LinkedNode(val);
            p->next->next = tmp;
            _size++;
        }

    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size)
            return;
        LinkedNode* p = _dummyHead;
        while (index--) {
            p = p->next;
                //index--;
        }
        LinkedNode* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        tmp = nullptr;
        _size--;
    }
};


