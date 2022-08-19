/*
 * @Descroption: LeetCode 500. 键盘行
 * @Author: EmoryHuang
 * @Date: 2021-04-24 14:17:36
 * @解题思路:
 * 遍历，记录每个单词的位置，若位于同一行则为需要的结果
 */

class Solution {
   public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string s[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for (auto word : words) {
            int count[3] = {0};  // 记录每个单词的位置
            for (auto c : word) {
                c = tolower(c);  // 转为小写
                for (int i = 0; i < 3; i++)
                    if (s[i].find(c) != string::npos) count[i]++;
            }
            int len = word.size();
            // 位于同一行
            if (count[0] == len || count[1] == len || count[2] == len) ans.push_back(word);
        }
        return ans;
    }
};