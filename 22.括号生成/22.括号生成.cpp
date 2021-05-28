/*
 * @Descroption: LeetCode 22. ��������
 * @Author: EmoryHuang
 * @Date: 2021-05-28 15:16:17
 * @����˼·:
 * dfs + ��֦
 * ���������ŵ��������� n �򷵻�
 * �������ŵ��������������ŵ������򷵻�
 */

class Solution {
   public:
    /**
     * @param {int} l �����ŵ�����
     * @param {int} r �����ŵ�����
     */
    void dfs(vector<string>& ans, string str, int l, int r, int n) {
        if (l > n || r > n || r > l) return;
        if (l == n && r == n) {
            ans.push_back(str);
            return;
        }
        dfs(ans, str + '(', l + 1, r, n);
        dfs(ans, str + ')', l, r + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, "", 0, 0, n);
        return ans;
    }
};