#pragma once
class Solution707
{
public:
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode() : val(-1), next(nullptr) {}
        LinkedNode(int x) : val(x), next(nullptr) {}
        LinkedNode(int x, LinkedNode* nex) : val(x), next(nex) {}
    };

    Solution707() {
        _dummy_head = new LinkedNode();
        _size = 0;
    }

    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* p = _dummy_head->next;
        while (index--) {
            p = p->next;
        }
        return p->val;
    }

    void addAtHead(int val) {
        LinkedNode* tmp = new LinkedNode(val);
        tmp->next = _dummy_head->next;
        _dummy_head->next = tmp;
        _size++;
    }

    void addAtTail(int val) {
        LinkedNode* p = _dummy_head;
        while (p->next) {
            p = p->next;
        }
        LinkedNode* new_node = new LinkedNode(val);
        p->next = new_node;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size)
            return;
        if (index <= 0) {
            this->addAtHead(val);
            return;
        }
        if (index == _size) {
            this->addAtTail(val);
            return;
        }
        LinkedNode* p = _dummy_head;
        while (index--) {
            p = p->next;
        }
        LinkedNode* new_node = new LinkedNode(val);
        new_node->next = p->next;
        p->next = new_node;
        _size++;
        return;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > (_size - 1))
            return;
        LinkedNode* p = _dummy_head;
        while (index--) {
            p = p->next;
        }
        LinkedNode* tmp = p->next;
        p->next = p->next->next;
        _size--;
        delete tmp;
        return;
    }
private:
    LinkedNode* _dummy_head;
    int _size;
};

