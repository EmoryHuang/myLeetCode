/*
 * @Descroption: LeetCode 1573. 分割字符串的方案数
 * @Author: EmoryHuang
 * @Date: 2021-08-14 14:43:40
 * @Method:
 * 排列组合
 * 计数字符串中1的位置和数量
 * 若 1 的数量为 0，说明没有 1，那么结果为C(2,n-1)，即 (n - 1) * (n - 2) / 2
 * 否则，考虑每两个部分之间最后一个 1 和第一个 1 的距离
 * 然后根据排列组合原理计算
 */

class Solution {
   public:
    int numWays(string s) {
        vector<int> ones;
        int n = s.size();
        for (int i = 0; i < n; i++)
            if (s[i] == '1') ones.push_back(i);
        int cnt = ones.size();
        if (cnt % 3 != 0) return 0;
        if (cnt == 0) {
            long long ways = (long long)(n - 1) * (n - 2) / 2;
            return ways % 1000000007;
        } else {
            int ind1 = cnt / 3, ind2 = cnt / 3 * 2;
            int cnt1 = ones[ind1] - ones[ind1 - 1];
            int cnt2 = ones[ind2] - ones[ind2 - 1];
            long long ways = (long long)cnt1 * cnt2;
            return ways % 1000000007;
        }
    }
};