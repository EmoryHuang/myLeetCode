/*
 * @Descroption: LeetCode 560. 和为K的子数组
 * @Author: EmoryHuang
 * @Date: 2021-05-29 14:08:56
 * @解题思路:
 * 首先计算一维前缀和
 * 搜索所有子数组需要枚举「左边界」和「右边界」（超时）
 *
 * 通过哈希表优化
 * 枚举右边界
 * 把「右边界」到「左端点」的数组和 cur 存入哈希表
 * 我们希望找到和为 k 的子数组
 * 这等价于从「哈希表」中找到一个 x，使得 cur - x = k
 */

class Solution {
   public:
    // 朴素一维前缀和（超时）
    // int subarraySum(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> pre(n + 1);
    //     for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1];
    //     int ans = 0;
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= i; j++) {
    //             int sum = pre[i] - pre[j - 1];
    //             if (sum == k) ans++;
    //         }
    //     }
    //     return ans;
    // }

    // 哈希表优化
    // int subarraySum(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> pre(n + 1);
    //     for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1];
    //     int ans = 0;
    //     map<int, int> mp;
    //     for (int i = 1; i <= n; i++) {
    //         int cur = pre[i];
    //         if (cur == k) ans++;
    //         if (mp.count(cur - k)) ans += mp[cur - k];
    //         mp[cur]++;
    //     }
    //     return ans;
    // }

    // 哈希表
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, cur = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int num : nums) {
            cur += num;
            ans += mp[cur - k];
            mp[cur]++;
        }
        return ans;
    }
};