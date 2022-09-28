/*
 * @Descroption: LeetCode 698. 划分为k个相等的子集
 * @Author: EmoryHuang
 * @Date: 2022-09-20 14:07:42
 * @Method:
 * dfs + 状态压缩 + 剪枝
 * 使用 used 记录使用过的数字，cur 记录当前和
 * dfs 遍历所有可能，判断数字是否使用过，未使用则继续搜索
 */

class Solution {
    boolean[] dp;

    boolean dfs(int[] nums, int used, int cur, int t) {
        // used 记录使用过的数字，cur 记录当前和
        if (used == 0)
            return true;
        // 记忆化搜索
        if (!dp[used])
            return dp[used];
        dp[used] = false;
        for (int i = 0; i < nums.length; i++) {
            // 超过则停止
            if (nums[i] + cur > t)
                break;
            // 判断数字是否使用过，未使用则继续搜索
            if ((((used >> i) & 1) != 0) && dfs(nums, used ^ (1 << i), (nums[i] + cur) % t, t))
                return true;
        }
        return false;
    }

    public boolean canPartitionKSubsets(int[] nums, int k) {
        int total = 0;
        for (int num : nums)
            total += num;
        if (total % k != 0)
            return false;
        Arrays.sort(nums);
        int n = nums.length, t = total / k;
        if (nums[n - 1] > t)
            return false;
        dp = new boolean[1 << n];
        Arrays.fill(dp, true);
        return dfs(nums, (1 << n) - 1, 0, t);
    }
}