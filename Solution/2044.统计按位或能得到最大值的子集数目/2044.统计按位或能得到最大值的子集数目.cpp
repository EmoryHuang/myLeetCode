/*
 * @Descroption: LeetCode 2044. 统计按位或能得到最大值的子集数目
 * @Author: EmoryHuang
 * @Date: 2022-03-15 10:22:32
 * @Method:
 * 方法一：二进制枚举
 * 二进制枚举，使用 n 位二进制记录 nums 中的每个数据是否被选择
 * 同时维护按位与能得到的最大值
 *
 * 方法二：dfs
 * 暴力枚举每个 num 是否被选择，并记录能得到的最大值
 */

class Solution {
   public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, max_num = 0;
        for (int s = 0; s < 1 << n; s++) {
            int cur_num = 0;
            for (int i = 0; i < n; i++) {
                if ((s >> i) & 1) cur_num |= nums[i];
            }
            if (cur_num > max_num) {
                max_num = cur_num;
                ans = 1;
            } else if (cur_num == max_num)
                ans++;
        }
        return ans;
    }

    // 方法二：dfs
    // int n, max_num = 0, ans = 0;
    // void dfs(int idx, int num, vector<int>& nums) {
    //     if (idx == n) {
    //         if (num > max_num) {
    //             max_num = num;
    //             ans = 1;
    //         } else if (num == max_num)
    //             ans++;
    //         return;
    //     }
    //     dfs(idx + 1, num, nums);
    //     dfs(idx + 1, num | nums[idx], nums);
    // }
    // int countMaxOrSubsets(vector<int>& nums) {
    //     n = nums.size();
    //     dfs(0, 0, nums);
    //     return ans;
    // }
};