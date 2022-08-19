/*
 * @Descroption: LeetCode 703. 数据流中的第 K 大元素
 * @Author: EmoryHuang
 * @Date: 2021-05-30 10:17:00
 * @解题思路:
 * 使用一个大小为 k 的优先队列来存储前 k 大的元素
 * 另外直接排序当然也可以
 */

class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) add(num);
    }

    int add(int val) {
        q.push(val);
        if (q.size() > k) q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */