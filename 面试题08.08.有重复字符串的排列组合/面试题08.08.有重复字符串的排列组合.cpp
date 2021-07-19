/*
 * @Descroption: ������ 08.08. ���ظ��ַ������������
 * @Author: EmoryHuang
 * @Date: 2021-07-19 15:28:58
 * @����˼·:
 * DFS ����
 * ʹ�� vis ��¼Ԫ���Ƿ���ʣ�ͨ��setȥ��
 */

class Solution {
   public:
    set<string> ans;
    string word;
    void dfs(string S, vector<bool> &vis) {
        if (word.size() == S.size()) {
            ans.insert(word);
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
        return vector<string>(ans.begin(), ans.end());
    }
};
