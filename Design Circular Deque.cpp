//https://leetcode.com/problems/design-circular-deque/description/


class MyCircularDeque {
private:
    deque<int> dq;
    int l;
    int size=0;
public:
    MyCircularDeque(int k) {
        l=k;
    }
    bool insertFront(int value) {
        if(size==l) return false;
        dq.push_front(value);
        size++;
        return true;
    }
    bool insertLast(int value) {
        if(size==l) return false;
        dq.push_back(value);
        size++;
        return true;
    }
    bool deleteFront() {
        if(size==0) return false;
        dq.pop_front();
        size--;
        return true;
    }
    bool deleteLast() {
        if(size==0) return false;
        dq.pop_back();
        size--;
        return true;
    }
    int getFront() {
        if(size==0) return -1;
        return dq.front();
    }
    int getRear() {
        if(size==0) return -1;
        return dq.back();
    }
    bool isEmpty() {
        return (size==0) ? true : false;
    }
    bool isFull() {
        return (size==l) ? true : false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
