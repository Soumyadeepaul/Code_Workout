//https://leetcode.com/problems/find-median-from-data-stream/description/


class MedianFinder {
private:
    vector<int> med;
    int l=0;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        auto it=upper_bound(med.begin(),med.end(),num);
        med.insert(it,num);
        l++;
    }
    
    double findMedian() {
        double d;
        if(l&1){
            d=med.at(l/2);
            
        }
        else{
            d=(double)(med.at((l/2)-1)+med.at(l/2))/2;
        }
        return d;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



//////////////////////////////////////////////////////////////////////////////////////////

class MedianFinder {
private:
    priority_queue<int> max_heap;//for smaller element
    priority_queue<int,vector<int>,greater<int>> min_heap;//for greater element
    int max_heapSize=0;
    int min_heapSize=0;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        min_heapSize++;
        if(min_heapSize>max_heapSize){
            max_heap.push(min_heap.top());
            min_heap.pop();
            max_heapSize++;
            min_heapSize--;
        }
    }
    
    double findMedian() {
        double d;
        if(min_heapSize<max_heapSize){
            d=max_heap.top();
        }
        else{
            d=(double)(min_heap.top()+max_heap.top())/2.0;
        }
        return d;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
