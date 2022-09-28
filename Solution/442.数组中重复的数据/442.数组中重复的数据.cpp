/*
 * @Descroption: LeetCode 442. 数组中重复的数据
 * @Author: EmoryHuang
 * @Date: 2022-05-08 10:48:57
 * @Method:
 * 方法一: 交换位置
 * 由于给定的 n 个数都在 [1, n] 的范围内
 * 对数组进行遍历, 当遍历到位置 i 时, nums[i] 应该被放在位置 nums[i] - 1
 * 因此我们交换 num[i] 和 nums[nums[i] - 1] 即可，直到待交换的两个元素相等为止
 *
 * 方法二: 正负号标识
 * 对 nums[i] 添加负号表示已经出现过
 * 遍历到位置 i 时，考虑 nums[nums[i] - 1] 的正负性
 */

class Solution {
   public:
    // 方法一: 交换位置
    // vector<int> findDuplicates(vector<int>& nums) {
    //     for (int i = 0; i < nums.size(); i++) {
    //         while (nums[i] != nums[nums[i] - 1]) {
    //             swap(nums[i], nums[nums[i] - 1]);
    //         }
    //     }
    //     vector<int> res;
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] != i + 1) {
    //             res.push_back(nums[i]);
    //         }
    //     }
    //     return res;
    // }

    // 方法二: 正负号标识
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int num = abs(nums[i]);
            if (nums[num - 1] < 0) {
                res.push_back(num);
            } else {
                nums[num - 1] = -nums[num - 1];
            }
        }
        return res;
    }
};