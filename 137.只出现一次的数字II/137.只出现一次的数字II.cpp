/*
 * @Descroption: LeetCode 137. 只出现一次的数字 II
 * @Author: EmoryHuang
 * @Date: 2021-04-30 20:04:36
 * @解题思路:
 * 使用哈希映射统计数组中每个元素的出现次数。在统计完成后，遍历哈希映射即可找出只出现一次的元素。
 *
 * 方法二位运算参考
 */

class Solution {
   public:
    // 方法一：哈希表
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int num : nums) mp[num]++;
        for (auto [num, c] : mp)
            if (c == 1) {
                ans = num;
                break;
            }
        return ans;
    }

    // 方法二：位运算
    // int singleNumber(vector<int>& nums) {
    //     int a = 0, b = 0;
    //     for (int num : nums) {
    //         b = ~a & (b ^ num);
    //         a = ~b & (a ^ num);
    //     }
    //     return b;
    // }
};