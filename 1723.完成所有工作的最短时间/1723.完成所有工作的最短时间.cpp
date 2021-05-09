class Solution {
   public:
    int ans = INT_MAX;
    void backtrace(vector<int>& jobs, int num, vector<int>& work, int maxTime) {
        if (num == jobs.size()) {  // 工作全部完成
            ans = min(ans, maxTime);
            return;
        }
        for (int i = 0; i < work.size(); i++) {
            if (work[i] + jobs[num] > ans) continue;  // 超过最大时间
            work[i] += jobs[num];
            backtrace(jobs, num + 1, work, max(maxTime, work[i]));
            work[i] -= jobs[num];  //撤销选择
            // 如果当前工人未被分配工作，那么下一个工人也必然未被分配工作
            // 或者当前工作恰能使该工人的工作量达到了上限
            if (work[i] == 0 || work[i] + jobs[num] == maxTime) break;
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> work(k);
        backtrace(jobs, 0, work, 0);
        return ans;
    }
};