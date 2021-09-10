/*
 * @Descroption: LeetCode 1672. 最富有客户的资产总量
 * @Author: EmoryHuang
 * @Date: 2021-05-19 20:23:31
 * @解题思路:
 * 简单题，求解二维数组行的最大元素和
 */

class Solution {
   public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = INT_MIN;
        for (auto account : accounts) {
            int tmp = 0;
            for (int num : account) tmp += num;
            ans = max(tmp, ans);
        }
        return ans;
    }
};