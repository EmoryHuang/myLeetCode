/*
 * @Descroption: 剑指 Offer 03. 数组中重复的数字
 * @Author: EmoryHuang
 * @Date: 2021-06-28 16:23:00
 * @解题思路:
 * 简单题，哈希表计数
 */

class Solution {
   public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> hash;
        for (auto num : nums)
            if (hash.count(num) != 0)
                return num;
            else
                hash.insert(num);
        return 0;
    }
};