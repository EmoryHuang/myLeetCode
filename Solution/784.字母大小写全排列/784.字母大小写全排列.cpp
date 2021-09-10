/*
 * @Descroption: LeetCode 784. 字母大小写全排列
 * @Author: EmoryHuang
 * @Date: 2021-07-26 14:27:15
 * @Method:
 * dfs回溯
 * 有大写小写两种可能
 */

class Solution {
   public:
    vector<string> ans;
    void dfs(string s, string path, int pos) {
        if (pos == s.size()) {
            ans.push_back(path);
            return;
        }
        if (isdigit(s[pos]))
            dfs(s, path + s[pos], pos + 1);
        else {
            path += tolower(s[pos]);
            dfs(s, path, pos + 1);
            path.pop_back();
            path += toupper(s[pos]);
            dfs(s, path, pos + 1);
            path.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        dfs(s, "", 0);
        return ans;
    }
};