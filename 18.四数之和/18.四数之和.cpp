/*
 * @Descroption: LeetCode 18. 四数之和
 * @Author: EmoryHuang
 * @Date: 2021-03-22 14:25:36
 * @解题思路: 和 三数之和
 * 类似的方法，只不过又多了一个循环，先排序，然后固定两个指针，内部再使用双指针
 */

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int len = nums.size();
        if (len < 4) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; i++) {          // 固定第一个指针
            for (int j = i + 1; j < len - 2; j++) {  // 固定第二个指针
                int left = j + 1, right = len - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target)
                        right--;
                    else if (sum < target)
                        left++;
                    else {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;  //跳过重复数字
                        while (left < right && nums[right] == nums[right - 1]) right--;  //跳过重复数字
                        left++;
                        right--;
                    }
                }
                while (j < len - 1 && nums[j] == nums[j + 1]) j++;  //跳过重复数字
            }
            while (i < len - 2 && nums[i] == nums[i + 1]) i++;  //跳过重复数字
        }
        return ans;
    }
};