/*
 * @Descroption: 剑指 Offer 50. 第一个只出现一次的字符
 * @Author: EmoryHuang
 * @Date: 2021-07-29 19:31:35
 * @Method:
 * 简单题，使用哈希表计数
 */

class Solution {
   public:
    char firstUniqChar(string s) {
        unordered_map<int, int> hash;
        for (auto c : s) hash[c]++;
        for (auto c : s)
            if (hash[c] == 1) return c;
        return ' ';
    }
};