/*
 * @Descroption: LeetCode 216. ����ܺ� III
 * @Author: EmoryHuang
 * @Date: 2021-05-20 16:50:37
 * @����˼·:
 * dfs����
 * ���� 9 ������ѡ�� k �����������ö�٣�
 * ����ö�ٵ���������ϣ��ж���������Ԫ��֮���Ƿ�Ϊ n
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> comb;
    void dfs(int k, int n, int cur) {
        if (n == 0 && comb.size() == k) ans.push_back(comb);
        if (n <= 0 || comb.size() > k) return;
        for (int i = cur; i <= 9; i++) {
            comb.push_back(i);
            dfs(k, n - i, i + 1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }
};