/*
 * @Descroption: LeetCode 826. 安排工作以达到最大收益
 * @Author: EmoryHuang
 * @Date: 2021-06-19 15:03:00
 * @解题思路:
 * 按照工人能力大小排序
 * 对于每个工人，找到其能完成的工作的最大收益
 */

class Solution {
   public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int n = difficulty.size();
        for (int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        // i 指向第 i 个工作
        // tmp 为可以完成的工作的最大利润
        int i = 0, ans = 0, tmp = 0;
        for (int j = 0; j < worker.size(); j++) {  // 遍历每个工人
            while (i < n && jobs[i].first <= worker[j]) {
                // 若当前工人可完成该工作
                tmp = max(tmp, jobs[i].second);  // 找到利润最大的工作
                i++;
            }
            ans += tmp;
        }
        return ans;
    }
};