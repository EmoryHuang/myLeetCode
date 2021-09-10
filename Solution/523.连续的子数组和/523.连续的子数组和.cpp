/*
 * @Descroption: LeetCode 523. 连续的子数组和
 * @Author: EmoryHuang
 * @Date: 2021-06-02 11:45:00
 * @解题思路:
 * 预处理前缀和数组 pre。然后假定 [i, j] 是我们的目标区间，那么有：
 * sum[j] - sum[i - 1] = n * k
 * 要使得两者除 k 相减为整数，需要满足 sum[j] 和 sum[i - 1] 对 k 取余相同
 *
 * 使用哈希表保存出现过的余数
 * 如果当前余数在哈希表中已经存在，并且子数组大小至少为 2，则存在
 * 如果当前余数在哈希表中不存在，则将当前余数和当前下标 i 的键值对存入哈希表中
 */

class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = -1;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre = (pre + nums[i]) % k;  // 前缀和的余数
            // 若有同余前缀和，并且子数组大小至少为 2
            if (mp.count(pre) != 0 && i - mp[pre] > 1)
                return true;
            else if (mp.count(pre) == 0)
                mp[pre] = i;  // 记录这个余数首次出现的位置
        }
        return false;
    }
};