/*
 * @Descroption: LeetCode 80. 删除有序数组中的重复项 II
 * @Author: EmoryHuang
 * @Date: 2021-04-06 17:49:36
 * @解题思路: 基本思路与[删除有序数组中的重复项]相同，设置快慢指针
 * 但是不同的是，每个元素 最多出现两次，可以通过设置 `flag` 计数判断重复项
 */

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int len = 0, flag = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[len] != nums[i]) {
                nums[++len] = nums[i];
                flag = 0;                                    // 重置 flag
            } else if (nums[len] == nums[i] && flag == 0) {  // 第一次重复项
                nums[++len] = nums[i];
                flag++;
            }
        }
        return ++len;
    }
};