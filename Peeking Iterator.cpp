//https://leetcode.com/problems/peeking-iterator/description/


/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int val=0;
    bool nextt=false;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    nextt=Iterator::hasNext();
        if(nextt) val=Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int curr=val;
        nextt=Iterator::hasNext();
        if(nextt) val=Iterator::next();
        return curr;
	}
	
	bool hasNext() const {
	    return nextt;
	}
};


///


// class PeekingIterator : public Iterator {
// private:
//     int idx=0;
//     vector<int> store;
// public:
// 	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
// 	    // Initialize any member here.
// 	    // **DO NOT** save a copy of nums and manipulate it directly.
// 	    // You should only use the Iterator interface methods.
// 	    for(int i:nums){
//             store.push_back(i);
//         }
// 	}
	
//     // Returns the next element in the iteration without advancing the iterator.
// 	int peek() {
//         return store[idx];
// 	}
	
// 	// hasNext() and next() should behave the same as in the Iterator interface.
// 	// Override them if needed.
// 	int next() {
// 	    return store[idx++];
// 	}
	
// 	bool hasNext() const {
// 	    if(idx<store.size()) return true;
//         return false;
// 	}
// };
