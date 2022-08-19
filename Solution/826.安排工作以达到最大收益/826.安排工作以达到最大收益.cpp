/*
 * @Descroption: LeetCode 826. ���Ź����Դﵽ�������
 * @Author: EmoryHuang
 * @Date: 2021-06-19 15:03:00
 * @����˼·:
 * ���չ���������С����
 * ����ÿ�����ˣ��ҵ�������ɵĹ������������
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
        // i ָ��� i ������
        // tmp Ϊ������ɵĹ������������
        int i = 0, ans = 0, tmp = 0;
        for (int j = 0; j < worker.size(); j++) {  // ����ÿ������
            while (i < n && jobs[i].first <= worker[j]) {
                // ����ǰ���˿���ɸù���
                tmp = max(tmp, jobs[i].second);  // �ҵ��������Ĺ���
                i++;
            }
            ans += tmp;
        }
        return ans;
    }
};