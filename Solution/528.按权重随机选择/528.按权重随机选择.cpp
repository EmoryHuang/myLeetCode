/*
 * @Descroption: LeetCode 528. 按权重随机选择
 * @Author: EmoryHuang
 * @Date: 2021-08-30 22:10:30
 * @Method:
 * 前缀和 + 二分
 * 每个元素代表一个权重，数字越大的元素，它的权重越大
 * 可以使用前缀和数组来作为权重分布序列
 * 随机数从前缀和数组中产生
 * 通过这个随机数，再定位到数组的下标即可
 */

class Solution {
   public:
    vector<int> pre;
    Solution(vector<int>& w) {
        pre.push_back(w[0]);
        for (int i = 1; i < w.size(); i++) pre.push_back(pre.back() + w[i]);
    }

    int pickIndex() {
        int n = pre.size();
        int seed = rand() % pre.back();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (pre[mid] > seed)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */