/*
 * @Descroption: LeetCode 1695. 删除子数组的最大得分
 * @Author: EmoryHuang
 * @Date: 2021-08-10 14:57:39
 * @Method:
 * 滑动窗口
 * 遍历数组，若当前元素未加入，则加入窗口，
 * 否则若遍历到了重复元素，则移动左窗口，删除重复元素之前的所有元素
 */

class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        int ans = 0, sum = 0;
        unordered_set<int> hash;
        while (r < n) {
            // 若当前元素未加入
            if (hash.count(nums[r]) == 0) {
                hash.insert(nums[r]);
                sum += nums[r];
                ans = max(ans, sum);
            } else {
                // 删除重复元素之前的所有元素
                while (nums[l] != nums[r]) {
                    sum -= nums[l];
                    hash.erase(nums[l]);
                    l++;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};