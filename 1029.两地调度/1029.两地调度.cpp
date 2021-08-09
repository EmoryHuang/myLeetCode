/*
 * @Descroption: LeetCode 1029. ���ص���
 * @Author: EmoryHuang
 * @Date: 2021-08-09 14:03:47
 * @Method:
 * ���� price_A - price_B ��С��������
 * ��ǰ N ���˷��� A �У������˷��� B ��
 */

class Solution {
   public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        int ans = 0;
        sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) { return a[0] - a[1] < b[0] - b[1]; });
        for (int i = 0; i < n; i++) ans += costs[i][0] + costs[i + n][1];
        return ans;
    }
};