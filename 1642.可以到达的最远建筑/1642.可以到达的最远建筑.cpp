/*
 * @Descroption: LeetCode 1642. 可以到达的最远建筑
 * @Author: EmoryHuang
 * @Date: 2021-07-24 14:41:33
 * @解题思路:
 * 维护一个最小堆
 * 将gap加入最小堆，优先将梯子用在间隔最大的地方，小间隔采用砖块
 * 最后砖块的个数小于0时返回
 */

class Solution {
   public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> heap;
        int n = heights.size();
        for (int i = 1; i < n; i++) {
            int gap = heights[i] - heights[i - 1];
            // 只有向上才需要用到梯子
            if (gap > 0) {
                // 将gap加入最小堆
                heap.push(gap);
                // 优先将梯子用在间隔最大的地方
                if (heap.size() > ladders) {
                    // 小间隔采用砖块
                    bricks -= heap.top();
                    heap.pop();
                    // 砖块的个数小于0时返回
                    if (bricks < 0) return i - 1;
                }
            }
        }
        return n - 1;
    }
};