/*
 * @Descroption: LeetCode 15. 三数之和
 * @Author: EmoryHuang
 * @Date: 2021-03-21 11:05:36
 * @解题思路: 首先，直接 for 循环暴力想都不用想，肯定超时，那么问题就在于如何剪枝，以及去除重复解
 *      这里采用排序加双指针的做法，遍历排序后数组，固定一个数`nums[i]`，再使用左右指针`j`,`k`指向`nums[i]`后面的两端
 *      若和大于 `0`，说明 `nums[k]` 太大，k 左移；若和小于 `0`，说明`nums[j]`太小，j 右移
 *      对于重复元素：跳过，避免出现重复解
 */

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        if (len < 3) return ans;  //元素个数不满3个
        sort(nums.begin(), nums.end());
        if (nums[0] > 0) return ans;  //若数组元素都大于0
        for (int i = 0; i < len; i++) {
            int j = i + 1, k = len - 1;  //双指针
            while (j < k) {
                if (nums[j] + nums[k] > -nums[i])
                    k--;
                else if (nums[j] + nums[k] < -nums[i])
                    j++;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;  //跳过重复数字
                    while (j < k && nums[k] == nums[k - 1]) k--;  //跳过重复数字
                    j++;                                          //移动指针
                    k--;
                }
            }
            while (i + 1 < len && nums[i] == nums[i + 1]) i++;  //跳过重复数字
        }
        return ans;
    }
};