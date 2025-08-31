//https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());  // create Heap
        while(k!=1){
            pop_heap(nums.begin(),nums.end()); // send largest element to the leaf
            nums.pop_back();   //removes the element from the leaf
            k--;
        }
        return nums.front();//root element
    }
};

//nums.push_back(x)   //take it into the vector
//push_heap(n.begin,n.end) // heapify
