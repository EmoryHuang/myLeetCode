/*
 * @Descroption: LeetCode 500. ������
 * @Author: EmoryHuang
 * @Date: 2021-04-24 14:17:36
 * @����˼·:
 * ��������¼ÿ�����ʵ�λ�ã���λ��ͬһ����Ϊ��Ҫ�Ľ��
 */

class Solution {
   public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string s[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for (auto word : words) {
            int count[3] = {0};  // ��¼ÿ�����ʵ�λ��
            for (auto c : word) {
                c = tolower(c);  // תΪСд
                for (int i = 0; i < 3; i++)
                    if (s[i].find(c) != string::npos) count[i]++;
            }
            int len = word.size();
            // λ��ͬһ��
            if (count[0] == len || count[1] == len || count[2] == len) ans.push_back(word);
        }
        return ans;
    }
};