/*
 * @Descroption: LeetCode 217. 存在重复元素
 * @Author: EmoryHuang
 * @Date: 2021-03-21 15:22:36
 * @解题思路:
 * 方法一：先排序，再遍历
 *
 * 方法二：利用 unordered_set
 */

class Solution {
   public:
    // 方法一：先排序，再遍历
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }

    // 方法二：利用unordered_set
    // bool containsDuplicate(vector<int>& nums) {
    //     int len = nums.size();
    //     unordered_set<int> st;
    //     for (int i = 0; i < len; i++) {
    //         if (st.find(nums[i]) == st.end())
    //             st.insert(nums[i]);
    //         else
    //             return true;
    //     }
    //     return false;
    // }
};