/*
 * @Descroption: LeetCode 1528. ���������ַ���
 * @Author: EmoryHuang
 * @Date: 2021-04-22 15:09:36
 * @����˼·:
 * ���⣬�����ַ�����Ȼ��λ�����ַ���Ӧ����
 */

class Solution {
   public:
    string restoreString(string s, vector<int>& indices) {
        string ans(s.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};