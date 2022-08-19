/*
 * @Descroption: LeetCode 1962. 移除石子使总数最小
 * @Author: EmoryHuang
 * @Date: 2021-10-21 09:20:05
 * @Method:
 * 大根堆
 * 维护一个大根堆，取堆顶元素 / 2 再入堆，计算堆内元素之和
 */

class Solution {
   public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(), piles.end());
        while (k--) {
            int cur = heap.top();
            heap.pop();
            heap.push((cur + 1) >> 1);
        }
        int ans = 0;
        while (!heap.empty()) {
            ans += heap.top();
            heap.pop();
        }
        return ans;
    }
};