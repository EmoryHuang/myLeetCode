/*
 * @Descroption: LeetCode 1738. �ҳ��� K ����������ֵ
 * @Author: EmoryHuang
 * @Date: 2021-05-19 19:24:31
 * @����˼·:
 * ����һ����άǰ׺��� + ����
 * dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i][j]
 * �ڵõ������еĶ�άǰ׺��֮������ֻ��Ҫ�ҳ����е� k ���Ԫ�ؼ�Ϊ�𰸡�
 *
 * ����������άǰ׺��� + С����
 * ͬһ�ķ������ƣ������άǰ׺��򣬵�ʹ��С�����ҳ����е� k ���Ԫ��
 */

class Solution {
   public:
    // ����һ����άǰ׺��� + ����
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

    // ����������άǰ׺��� + С����
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