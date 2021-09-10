/*
 * @Descroption: LeetCode 1787. 使所有区间的异或结果为零
 * @Author: EmoryHuang
 * @Date: 2021-05-25 11:31:11
 * @解题思路:
 * 首先，答案数组必然是每 k 个一组进行重复的
 * 因此可以将这个一维的输入看成二维，
 * 从而将问题转化为：使得最终每列相等，同时「首行」的异或值为 0 的最小修改次数。
 *
 * dp[i][j] 表示每个窗口中前 i 个数字进行异或，得到 j 所需的最小次数
 * 使用哈希表记录每一列的数字分别出现了多少次，使用变量 cnt 统计该列有多少数字
 * 对于某一列数字最多操作count[i]次，这时相当于改变所有数字
 * dp[i][j]应该取 dp[i-1] 中的最小值 + count[i]
 *
 * dp[i][j ^ num] = min(dp[i][j ^ num], dp[i - 1][j] + change(num))
 * 说明：
 * 若不需要改变当前列的数字num，那么取 min(dp[i-1][0]~dp[i-1][1024]+cnt[i])，也就是上面说的
 * 若需要改变当前列的数字num，那么取 dp[i - 1][j] + change(num)，change(num)为需要改变的数组个数
 * 转移取最小值，最终就应该为dp[k-1][0]
 */

class Solution {
   public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAX = 1024;
        vector<int> count(k);
        vector<unordered_map<int, int>> hash(k);
        for (int i = 0; i < n; i++) {
            count[i % k]++;          // 该列数字总数
            hash[i % k][nums[i]]++;  // 每一列的数字分别出现了多少次
        }
        // dp[i][j] 表示每个窗口中前 i 个数字进行异或，得到 j 所需的最小次数
        vector<vector<int>> dp(k, vector<int>(MAX));
        for (int j = 0; j < MAX; j++) dp[0][j] = count[0] - hash[0][j];  // 初始化
        for (int i = 1; i < k; i++) {
            int minc = *min_element(dp[i - 1].begin(), dp[i - 1].end());  // 前一列需要改变的最小值
            // 对于某一列数字最多操作count[i]次，这时相当于改变所有数字
            // dp[i][j]应该取 dp[i-1] 中的最小值 + count[i]
            for (int j = 0; j < MAX; j++) dp[i][j] = minc + count[i];
            for (auto p : hash[i % k]) {  // 遍历每一列的值
                for (int j = 0; j < MAX; j++) {
                    int num = p.first, c = p.second;
                    dp[i][j ^ num] = min(dp[i][j ^ num], dp[i - 1][j] + count[i] - c);
                }
            }
        }
        return dp[k - 1][0];
    }
};