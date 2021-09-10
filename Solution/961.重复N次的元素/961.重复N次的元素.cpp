/*
 * @Descroption: LeetCode 961. 重复 N 次的元素
 * @Author: EmoryHuang
 * @Date: 2021-06-28 14:40:00
 * @解题思路:
 * 简单题，哈希表计数
 */

class Solution {
   public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> st;
        for (auto num : nums) {
            if (!st.count(num))
                st.insert(num);
            else
                return num;
        }
        return 0;
    }
};