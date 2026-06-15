//https://leetcode.com/problems/kth-largest-element-in-a-stream/description/


class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minpq;
    int k=0;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i:nums)minpq.push(i);
        while(minpq.size()>k){
            minpq.pop();
        }
    }
    
    int add(int val) {
        minpq.push(val);
        while(minpq.size()>k){
            minpq.pop();
        }
        int element=minpq.top();
        return element;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
