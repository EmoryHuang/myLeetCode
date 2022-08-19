/*
 * @Descroption: LeetCode 502. IPO
 * @Author: EmoryHuang
 * @Date: 2021-09-08 15:17:42
 * @Method:
 * 堆
 * 最大化资本时，我们不需要减去启动资金，只需要考虑纯利润
 * 基本思想是这样的，首先，我们按启动资金从小到大进行排序
 * 接着选择k个项目，在选择项目时，将所有的启动资金不超过 w 的项目加入优先队列
 * 选择利润最大的那个项目即可
 */

class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> p;
        // 按启动资金从小到大进行排序
        for (int i = 0; i < n; i++) p.push_back({capital[i], profits[i]});
        sort(p.begin(), p.end());
        priority_queue<int> heap;
        int i = 0;
        while (k--) {
            // 将所有的启动资金不超过 w 的任务加入优先队列
            while (i < n && p[i].first <= w) {
                heap.push(p[i++].second);
            }
            if (heap.empty()) break;  // 队列为空
            // 从队列中选择利润最大的项目
            w += heap.top();
            heap.pop();
        }
        return w;
    }
};