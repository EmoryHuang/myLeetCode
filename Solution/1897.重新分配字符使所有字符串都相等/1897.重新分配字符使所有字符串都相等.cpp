/*
 * @Descroption: LeetCode 1897. 重新分配字符使所有字符串都相等
 * @Author: EmoryHuang
 * @Date: 2021-07-20 20:05:18
 * @解题思路:
 * 使用哈希表记录每个字符的数量
 * 若字符的个数不是数组长度的整数倍，则满足
 */
 
class Solution {
   public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> mp(26);
        for (auto word : words)
            for (auto ch : word) mp[ch - 'a']++;
        for (auto num : mp)
            if (num % n != 0) return false;
        return true;
    }
};