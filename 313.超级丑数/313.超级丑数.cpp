/*
 * @Descroption: LeetCode 313. 超级丑数
 * @Author: EmoryHuang
 * @Date: 2021-08-09 13:46:59
 * @Method:
 * 方法一：最小堆
 * 每次取出堆顶元素 x，则 x 是堆中最小的超级丑数
 * 对于数组 primes 的任意质数 p，px 也是超级丑数，因此将乘积加入堆
 * 重复操作n次即是第n个超级丑数
 * 方法二：动态规划
 * dp[i] 表示第i个超级丑数
 * 使用m个指针分别指向dp[i]的primes[i]倍数，若遍历到则跳过
 */

class Solution {
   public:
    // 方法一：最小堆
    // int nthSuperUglyNumber(int n, vector<int>& primes) {
    //     priority_queue<int, vector<int>, greater<int>> q;
    //     set<int> vis = {1};
    //     int ugly;
    //     q.push(1);
    //     for (int i = 0; i < n; i++) {
    //         ugly = q.top();
    //         q.pop();
    //         for (auto prime : primes) {
    //             int next = ugly * prime;
    //             if (vis.count(next) == 0) {
    //                 vis.insert(next);
    //                 q.push(next);
    //             }
    //         }
    //     }
    //     return ugly;
    // }

    // 方法二：动态规划
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n + 1);
        int m = primes.size();
        vector<int> p(m + 1, 1);
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            int minn = INT_MAX;
            for (int j = 0; j < m; j++) minn = min(minn, primes[j] * dp[p[j]]);
            dp[i] = minn;
            for (int j = 0; j < m; j++)
                if (primes[j] * dp[p[j]] == minn) p[j]++;
        }
        return dp[n];
    }
};