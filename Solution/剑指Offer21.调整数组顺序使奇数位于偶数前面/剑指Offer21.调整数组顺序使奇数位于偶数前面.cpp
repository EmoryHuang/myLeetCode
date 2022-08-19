/*
 * @Descroption: 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
 * @Author: EmoryHuang
 * @Date: 2021-06-30 20:46:00
 * @解题思路:
 * 维护两个指针
 * 方法一：快慢指针
 * fast 遍历数组元素，slow 记录奇数位置
 * 方法二：头尾指针
 */

class Solution {
   public:
    // 方法二：快慢指针
    vector<int> exchange(vector<int>& nums) {
        int fast = 0, slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] & 1) {  // 如果是奇数
                swap(nums[fast], nums[slow]);
                slow++;
            }
            fast++;
        }
        return nums;
    }

    // 方法二：头尾指针
    // vector<int> exchange(vector<int>& nums) {
    //     int l = 0, r = nums.size() - 1;
    //     while (l < r) {
    //         while (l < r && nums[l] % 2 == 1) l++;
    //         while (l < r && nums[r] % 2 == 0) r--;
    //         swap(nums[l], nums[r]);
    //         l++, r--;
    //     }
    //     return nums;
    // }
};