/*
 * @Descroption: LeetCode 383. 赎金信
 * @Author: EmoryHuang
 * @Date: 2021-05-20 19:51:37
 * @解题思路:
 * 使用哈希表记录magazine中字符出现的次数，之后遍历ransomNote，若不足则返回false
 */

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        for (auto c : magazine) mp[c]++;
        for (auto c : ransomNote) {
            mp[c]--;
            if (mp[c] < 0) return false;
        }
        return true;
    }
};