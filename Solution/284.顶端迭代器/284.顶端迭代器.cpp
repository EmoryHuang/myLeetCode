/*
 * @Descroption: LeetCode 284. 顶端迭代器
 * @Author: EmoryHuang
 * @Date: 2021-05-28 13:48:17
 * @解题思路:
 * 记录 val 和 hasnext
 */

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
   public:
    int val;
    bool hasnext;
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        hasnext = Iterator::hasNext();
        if (hasnext) val = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() { return val; }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int cur = val;
        hasnext = Iterator::hasNext();
        if (hasnext) val = Iterator::next();
        return cur;
    }

    bool hasNext() const { return hasnext; }
};