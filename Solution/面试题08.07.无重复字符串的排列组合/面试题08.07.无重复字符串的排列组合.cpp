/*
 * @Descroption: 面试题 08.07. 无重复字符串的排列组合
 * @Author: EmoryHuang
 * @Date: 2021-07-19 15:08:19
 * @解题思路:
 * DFS 回溯
 * 使用 vis 记录元素是否访问
 */

class Solution {
   public:
    vector<string> ans;
    string word;
    void dfs(string S, vector<bool> &vis) {
        if (word.size() == S.size()) {
            ans.push_back(word);
            return;
        }
        for (int i = 0; i < S.size(); i++) {
            if (!vis[i]) {
                word.push_back(S[i]);
                vis[i] = true;
                dfs(S, vis);
                word.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<string> permutation(string S) {
        vector<bool> vis(S.size());
        dfs(S, vis);
        return ans;
    }
};