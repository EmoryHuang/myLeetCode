/*
 * @Descroption: LeetCode 1723. 完成所有工作的最短时间
 * @Author: EmoryHuang
 * @Date: 2021-05-08 20:28:36
 * @解题思路:
 * 回溯 + 剪枝
 * 运用回溯的方法，`work[i]` 为第 `i` 个工人的当前工作时间，
 * 利用一个递归函数 `backtrack(i)` 递归地枚举第 `i` 个任务的分配方案，过程中实时地更新 `work` 数组
 * 剪枝：
 * - 如果第 `i` 个工人已经工作的工作时间 `work[i]` + 当前工作需要的时间 `jobs[num]`
 * 超过了之前找到的最小最大工作时间，那么不分配给第 `i` 个工人
 * - 如果当前工人未被分配工作，那么下一个工人也必然未被分配工作
 * - 如果当前工作恰使该工人的工作量达到了上限，那么不分配
 */

class Solution {
   public:
    int ans = INT_MAX;
    // work[i]为第i个工人的当前工作时间
    // num为当前工作序号
    // maxTime为完成前num件工作的最大工作时间
    void backtrack(vector<int>& jobs, int num, vector<int>& work, int maxTime) {
        if (num == jobs.size()) {     // 工作全部完成
            ans = min(ans, maxTime);  //更新最最小最大工作时间
            return;
        }
        for (int i = 0; i < work.size(); i++) {
            if (work[i] + jobs[num] > ans) continue;  // 超过最大时间
            work[i] += jobs[num];
            backtrack(jobs, num + 1, work, max(maxTime, work[i]));  //回溯
            work[i] -= jobs[num];                                   //撤销选择
            // 如果当前工人未被分配工作，那么下一个工人也必然未被分配工作
            // 或者当前工作恰能使该工人的工作量达到了上限
            if (work[i] == 0 || work[i] + jobs[num] == maxTime) break;
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> work(k);
        backtrack(jobs, 0, work, 0);
        return ans;
    }
};