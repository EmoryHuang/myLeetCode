/*
 * @Descroption: LeetCode 851. ���ֺ͸���
 * @Author: EmoryHuang
 * @Date: 2021-07-28 14:23:33
 * @Method:
 * dfs
 * �洢 richer �еĸ�ԣ��ϵ
 * ����ÿһ���ˣ��ҵ�������ԣ���ˣ�dfsѰ�ұ�����˸���ԣ����
 * ��dfs�Ĺ����У�������С�İ���ֵ
 */

class Solution {
   public:
    vector<vector<int>> mp;
    vector<int> ans;
    int dfs(vector<int> quiet, int x) {
        if (ans[x] == -1) {
            ans[x] = x;
            // ����ÿһ����x����ԣ����
            for (auto rich : mp[x]) {
                // dfs�ҵ�������˸���ԣ����
                int more_rich = dfs(quiet, rich);
                // ������С�İ���ֵ
                if (quiet[more_rich] < quiet[ans[x]]) ans[x] = more_rich;
            }
        }
        return ans[x];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        mp.resize(n);
        ans.resize(n, -1);
        // �洢��ԣ��ϵ
        for (auto rich : richer) mp[rich[1]].push_back(rich[0]);
        for (int i = 0; i < n; i++) dfs(quiet, i);
        return ans;
    }
};