/*
 * @Descroption: LeetCode 1738. 找出第 K 大的异或坐标值
 * @Author: EmoryHuang
 * @Date: 2021-05-19 19:24:31
 * @解题思路:
 * 方法一：二维前缀异或 + 排序
 * dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i][j]
 * 在得到了所有的二维前缀和之后，我们只需要找出其中第 k 大的元素即为答案。
 *
 * 方法二：二维前缀异或 + 小根堆
 * 同一的方法类似，计算二维前缀异或，但使用小根堆找出其中第 k 大的元素
 */

class Solution {
   public:
    // 方法一：二维前缀异或 + 排序
    // int kthLargestValue(vector<vector<int>>& matrix, int k) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    //     vector<int> ans;
    //     for (int i = 1; i <= m; i++) {
    //         for (int j = 1; j <= n; j++) {
    //             dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i - 1][j - 1];
    //             ans.push_back(dp[i][j]);
    //         }
    //     }
    //     sort(ans.begin(), ans.end(), greater<int>());
    //     return ans[k - 1];
    // }

    // 方法二：二维前缀异或 + 小根堆
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                q.push(dp[i][j]);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};