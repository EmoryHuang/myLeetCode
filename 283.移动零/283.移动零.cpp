/*
 * @Descroption: LeetCode 283. 移动零
 * @Author: EmoryHuang
 * @Date: 2021-05-17 16:42:26
 * @解题思路:
 * 双指针，i遍历数组，j记录非0数组长度
 * 如果nums[i]不为 0 则交换
 */
 
class Solution {
   public:
    void moveZeroes(vector<int> &nums) {
        if (nums.size() <= 1) return;
        int i = 0, j = 0;  // i遍历数组，j记录非0数组长度
        while (i < nums.size()) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);  // 如果不为0则交换
                j++;
            }
            i++;
        }
    }
};