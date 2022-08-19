/*
 * @Descroption: ��ָ Offer 38. �ַ���������
 * @Author: EmoryHuang
 * @Date: 2021-06-22 12:42:00
 * @����˼·:
 * ���ݷ���ʹ��setȥ��
 */

class Solution {
   public:
    set<string> ans;
    void dfs(string &s, string &cur, vector<bool> &vis, int ind) {
        if (ind == s.size()) {
            ans.insert(cur);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (!vis[i]) {
                cur.push_back(s[i]);
                vis[i] = true;
                dfs(s, cur, vis, ind + 1);
                cur.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<string> permutation(string s) {
        string cur;
        vector<bool> vis(s.size());
        dfs(s, cur, vis, 0);
        return vector<string>(ans.begin(), ans.end());
    }
};