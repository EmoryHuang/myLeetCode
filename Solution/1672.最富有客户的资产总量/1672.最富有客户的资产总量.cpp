/*
 * @Descroption: LeetCode 1672. ��пͻ����ʲ�����
 * @Author: EmoryHuang
 * @Date: 2021-05-19 20:23:31
 * @����˼·:
 * ���⣬����ά�����е����Ԫ�غ�
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