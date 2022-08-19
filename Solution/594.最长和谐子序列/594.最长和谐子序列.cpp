/*
 * @Descroption: LeetCode 594. 最长和谐子序列
 * @Author: EmoryHuang
 * @Date: 2021-10-13 08:57:40
 * @Method:
 * 方法一：排序 + 双指针
 * 由于是子序列并且只要求给出长度，因此可以直接排序，然后通过双指针找到最长和谐子序列的长度
 *
 * 方法二：哈希表
 * 使用哈希表记录元素出现的次数，num 可以和 num + 1 组成和谐子序列
 * 也就是找两个差值为 1 的数的最大总个数
 */

class Solution {
   public:
    // 方法一：排序 + 双指针
    // int findLHS(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     int l = 0, r = 0, ans = 0;
    //     for (; r < nums.size(); r++) {
    //         while (nums[r] - nums[l] > 1) l++;
    //         if (nums[r] - nums[l] == 1) ans = max(ans, r - l + 1);
    //     }
    //     return ans;
    // }

    // 方法二：哈希表
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hash;
        int ans = 0;
        for (int num : nums) {
            hash[num]++;
            if (hash[num - 1] > 0) ans = max(ans, hash[num] + hash[num - 1]);
            if (hash[num + 1] > 0) ans = max(ans, hash[num] + hash[num + 1]);
        }
        return ans;
    }
};