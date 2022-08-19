/*
 * @Descroption: LeetCode 62. 不同路径
 * @Author: EmoryHuang
 * @Date: 2021-03-21 20:30:36
 * @解题思路:
 * 首先想到的是动态规划，挺容易想到的，（i，j）可以通过（i-1，j）和（i，j-1）到达，可以得到：
 * mp[i][j] = mp[i - 1][j] + mp[i][j - 1]
 *
 * 第二个方法是组合数
 * 从左上角到右下角的过程中，我们需要移动 m + n - 2 次，
 * 其中有 m - 1 次向下移动， n - 1 次向右移动。
 * 因此路径的总数，就等于从 m + n - 2 次移动中选择 m - 1 次向下移动的方案数，即组合数 C(m+n-2,m-1)
 */

class Solution {
   public:
    // 方法一：动态规划
    int uniquePaths(int m, int n) {
        vector<vector<int>> mp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    mp[i][j] = 1;
                else
                    mp[i][j] = mp[i - 1][j] + mp[i][j - 1];
            }
        }
        return mp[m - 1][n - 1];
    }

    // 方法二：组合数
    // int uniquePaths(int m, int n) {
    //     long long ans = 1;
    //     for (int x = n, y = 1; y < m; ++x, ++y) {
    //         ans = ans * x / y;
    //     }
    //     return ans;
    // }
};