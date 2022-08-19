/*
 * @Descroption: LeetCode 387. 字符串中的第一个唯一字符
 * @Author: EmoryHuang
 * @Date: 2021-05-20 20:04:37
 * @解题思路:
 * 使用哈希表记录s中字符出现的次数,，之后查找出现次数为1的元素
 */

class Solution {
   public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        for (auto c : s) mp[c]++;
        for (int i = 0; i < s.size(); i++)
            if (mp[s[i]] == 1) return i;
        return -1;
    }
};