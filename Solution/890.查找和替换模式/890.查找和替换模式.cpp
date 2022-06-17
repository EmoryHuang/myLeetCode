/*
 * @Descroption: LeetCode 890. 查找和替换模式
 * @Author: EmoryHuang
 * @Date: 2022-06-12 09:55:10
 * @Method:
 * 使用哈希表记录字符之间的映射关系
 * 遍历所有单词，依次检查模式是否匹配
 */

class Solution {
   public:
    bool isMatch(string word, string pattern) {
        if (word.size() != pattern.size()) return false;
        unordered_map<char, char> map;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i], p = pattern[i];
            if (!map.count(ch)) {
                map[ch] = p;
            } else if (map[ch] != p) {
                return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto& word : words) {
            if (isMatch(word, pattern) && isMatch(pattern, word)) res.push_back(word);
        }
        return res;
    }
};