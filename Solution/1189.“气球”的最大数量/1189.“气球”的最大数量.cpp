/*
 * @Descroption: LeetCode 1189. “气球” 的最大数量
 * @Author: EmoryHuang
 * @Date: 2021-05-26 15:47:17
 * @解题思路:
 * 使用哈希表计数balloon中每个字符出现的次数
 */

class Solution {
   public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp;
        for (auto c : text) mp[c]++;
        return min({mp['a'], mp['b'], mp['l'] / 2, mp['n'], mp['o'] / 2});
    }
};