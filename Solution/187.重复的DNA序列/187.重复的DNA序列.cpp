/*
 * @Descroption: LeetCode 187. 重复的DNA序列
 * @Author: EmoryHuang
 * @Date: 2021-10-08 16:37:06
 * @Method:
 * 滑动窗口 + 哈希表
 * 滑动窗口大小为10，使用哈希表记录子序列出现的次数
 */

class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        vector<string> ans;
        for (int i = 0; i + 10 <= s.length(); i++) {
            string cur = s.substr(i, 10);
            if (hash[cur] == 1) ans.push_back(cur);
            hash[cur]++;
        }
        return ans;
    }
};