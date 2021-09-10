/*
 * @Descroption: LeetCode 295. 数据流的中位数
 * @Author: EmoryHuang
 * @Date: 2021-08-27 13:41:18
 * @Method:
 * 使用两个优先队列（堆）来维护整个数据流数据，
 * 维护数据流左半边数据的优先队列（堆）为 l，维护数据流右半边数据的优先队列（堆）为 r
 * l 为大根堆，r 为小根堆
 * 当数据流元素数量为偶数：l 和 r 大小相同，此时动态中位数为两者堆顶元素的平均值；
 * 当数据流元素数量为奇数：l 比 r 多一，此时动态中位数为 l 的堆顶原数。
 */

class MedianFinder {
   public:
    /** initialize your data structure here. */
    priority_queue<int> l;                             // 大根堆
    priority_queue<int, vector<int>, greater<int>> r;  // 小根堆
    MedianFinder() {}

    void addNum(int num) {
        // 如果l为空，或者num小于等于左半部分最大值
        if (l.empty() || l.top() >= num) {
            l.push(num);
            // 若左右部分的相差的数字个数大于1
            if (r.size() + 1 < l.size()) {
                // 将左半部分的最大值放到右半部分
                r.push(l.top());
                l.pop();
            }
        } else {
            r.push(num);
            if (r.size() > l.size()) {
                l.push(r.top());
                r.pop();
            }
        }
    }

    double findMedian() {
        if (l.size() == r.size()) return (l.top() + r.top()) / 2.0;
        return l.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */