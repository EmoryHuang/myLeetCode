class Solution {
   public:
    void dfs(vector<vector<int>>& ans, vector<int>& p, int n, int k, int st) {
        if (p.size() == k) {
            ans.push_back(p);
            return;
        }
        for (int i = st; i <= n; i++) {
            if (p.size() < k) {
                p.push_back(i);
                dfs(ans, p, n, k, i + 1);  // �ݹ�
                p.pop_back();              // ����ѡ��
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> p;
        dfs(ans, p, n, k, 1);
        return ans;
    }
};