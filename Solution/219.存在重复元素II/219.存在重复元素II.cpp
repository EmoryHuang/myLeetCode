/*
 * @Descroption: LeetCode 219. 存在重复元素 II
 * @Author: EmoryHuang
 * @Date: 2021-04-17 15:28:36
 * @解题思路:
 * 与 [217. 存在重复元素]类似
 * 对于已存在的元素，在`[0,i)`中再次寻找，判断下标
 */

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < len; i++) {
            if (st.find(nums[i]) == st.end())  // 集合中不存在
                st.insert(nums[i]);
            else {
                for (int j = 0; j < i; j++) {  // 在[0,i)中寻找
                    if (nums[i] == nums[j] && i - j <= k) return true;
                }
            }
        }
        return false;
    }
};