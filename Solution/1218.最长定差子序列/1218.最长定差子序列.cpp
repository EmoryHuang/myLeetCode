/*
 * @Descroption: LeetCode 1218. 最长定差子序列
 * @Author: EmoryHuang
 * @Date: 2021-08-10 13:47:58
 * @Method:
 * 动态规划 + 哈希表
 * 使用哈希表存放以nums[i]结尾的等差数列的数量
 * 若 num - difference 不在哈希表中，则置为 1
 * 否则，置为 hash[num - difference] + 1
 */

class Solution {
   public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> hash;
        for (int num : arr) {
            hash[num] = hash[num - difference] + 1;
        }
        int ans = 0;
        for (auto h : hash) ans = max(ans, h.second);
        return ans;
    }
};