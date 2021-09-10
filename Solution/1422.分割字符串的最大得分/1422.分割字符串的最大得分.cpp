/*
 * @Descroption: LeetCode 1422. 分割字符串的最大得分
 * @Author: EmoryHuang
 * @Date: 2021-08-08 14:15:25
 * @Method:
 * 统计0和1的数量
 */

class Solution {
   public:
    int maxScore(string s) {
        int zero = 0, one = 0, ans = 0;
        for (auto c : s)
            if (c == '1') one++;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0')
                zero++;
            else
                one--;
            ans = max(ans, zero + one);
        }
        return ans;
    }
};