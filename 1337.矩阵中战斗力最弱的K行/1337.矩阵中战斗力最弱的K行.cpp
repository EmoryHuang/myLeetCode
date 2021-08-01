/*
 * @Descroption: LeetCode 1337. 矩阵中战斗力最弱的 K 行
 * @Author: EmoryHuang
 * @Date: 2021-08-01 12:51:35
 * @Method:
 * 二分 + 最小堆
 * 由于 1 总是出现在 0 之前，那么使用二分法寻找右端点，找到每行1的个数
 * 然后建立最小堆，找到前k个最小值对应的行
 */

class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> power;
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + (r - l + 1) / 2;
                if (mat[i][mid] == 1)
                    l = mid;
                else
                    r = mid - 1;
            }
            l = mat[i][l] == 1 ? l + 1 : l;
            power.push_back({l, i});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q(power.begin(), power.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};