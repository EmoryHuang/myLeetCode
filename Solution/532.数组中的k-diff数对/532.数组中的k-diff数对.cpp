/*
 * @Descroption: LeetCode 532. 数组中的 k-diff 数对
 * @Author: EmoryHuang
 * @Date: 2022-06-15 09:05:24
 * @Method:
 * 使用哈希表记录出现的数字
 * 对于当前数字 num，如果 num - k 或 num + k 在哈希表中，则为 k-diff 数对
 */

class Solution {
   public:
    int findPairs(vector<int>& nums, int k) {
        set<int> vis, ans;
        for (int num : nums) {
            if (vis.find(num - k) != vis.end()) ans.insert(num - k);
            if (vis.find(num + k) != vis.end()) ans.insert(num);
            vis.insert(num);
        }
        return ans.size();
    }
};