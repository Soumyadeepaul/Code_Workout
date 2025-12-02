//https://leetcode.com/problems/design-circular-queue/?envType=problem-list-v2&envId=queue



class MyCircularQueue {
private:
    queue<int> q;
    int front=-1;
    int rare=-1;
    int l;
public:
    MyCircularQueue(int k) {
        l=k;
    }
    
    bool enQueue(int value) {
        if(rare==l-1) return false;
        q.push(value);
        if(front==-1)
            front++;
        rare++;
        return true;
    }
    
    bool deQueue() {
        if(rare==-1) return false;
        q.pop();
        if(rare==front) front--;
        rare--;
        return true;
    }
    
    int Front() {
        if (front==-1) return -1;
        return q.front();
    }
    
    int Rear() {
        if(rare==-1) return -1;
        return q.back();
    }
    
    bool isEmpty() {
        if(front==-1) return true;
        return false;
    }
    
    bool isFull() {
        if(rare==l-1) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
