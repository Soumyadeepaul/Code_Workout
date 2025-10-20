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
