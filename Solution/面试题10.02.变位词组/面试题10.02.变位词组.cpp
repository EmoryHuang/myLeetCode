/*
 * @Descroption: 面试题 10.02. 变位词组
 * @Author: EmoryHuang
 * @Date: 2021-07-18 14:00:49
 * @解题思路:
 * 使用长度为 26 的数组记录每个字母出现的次数
 * 然后以此作为键值，判断字符是否为同类
 */

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hash;
        vector<vector<string>> ans;
        for (auto str : strs) {
            string cnt = string(26, '0');
            for (auto c : str) cnt[c - 'a']++;
            hash[cnt].push_back(str);
        }
        for (auto str : hash) ans.push_back(str.second);
        return ans;
    }
};