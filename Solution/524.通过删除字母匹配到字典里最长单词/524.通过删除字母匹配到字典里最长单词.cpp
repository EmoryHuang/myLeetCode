/*
 * @Descroption: LeetCode 524. 通过删除字母匹配到字典里最长单词
 * @Author: EmoryHuang
 * @Date: 2021-09-14 11:29:25
 * @Method:
 * 双指针 + 排序
 * p, q 分别为指向 s 和 word 的指针
 * 若字符相等，则p，q向右移动；否则，p向右移动
 * 如果找到了一个字符串，则加入 ans
 * 按长度和字典序排序 ans
 */

class Solution {
   public:
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<string> ans;
        for (auto word : dictionary) {
            int p = 0, q = 0;
            while (p < s.size() && q < word.size()) {
                if (s[p] == word[q])
                    p++, q++;
                else
                    p++;
                if (q == word.size()) {
                    ans.push_back(word);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end(), [](string a, string b) {
            if (a.size() != b.size()) return a.size() > b.size();
            return a < b;
        });
        return ans.empty() ? "" : ans[0];
    }
};