/*
 * @Descroption: LeetCode 1449. 数位成本和为目标值的最大数字
 * @Author: EmoryHuang
 * @Date: 2021-06-12 21:53:00
 * @解题思路:
 * 完全背包问题
 * 若两个整数位数不同，位数更多的整数必然大于位数小的整数。
 * 因此我们需要先计算出可以得到的整数的最大位数
 * dp[j]表示总成本恰好为 j 时最大位数
 * 状态转移方程：dp[j] = max(dp[j], dp[j - cost] + 1)
 * 应该尽可能让高位的数值越大越好，
 * 因此我们可以从数值 9 开始往数值 1 遍历，如果状态能够由该数值转移而来，则选择该数值
 */

#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string largestNumber(vector<int>& cost, int target) {
        // dp[j]表示总成本恰好为 j 时最大位数
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (int c : cost)
            for (int j = c; j <= target; j++) dp[j] = max(dp[j], dp[j - c] + 1);
        if (dp[target] < 0) return "0";
        string ans;
        for (int i = 8, j = target; i >= 0; i--) {  // 从后往前遍历，cost最长为9
            while (j >= cost[i] && dp[j] == dp[j - cost[i]] + 1) {
                ans += to_string(i + 1);
                j -= cost[i];
            }
        }
        return ans;
    }
};