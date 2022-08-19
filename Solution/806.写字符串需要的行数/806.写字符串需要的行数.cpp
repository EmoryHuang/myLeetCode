/*
 * @Descroption: LeetCode 806. 写字符串需要的行数
 * @Author: EmoryHuang
 * @Date: 2021-04-25 15:50:36
 * @解题思路:
 * 简单题，若`sum`大于 100，则置 0，重新计数
 */

class Solution {
   public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int row = 1;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (sum + widths[s[i] - 'a'] > 100) {
                row++;
                sum = 0;
            }
            sum += widths[s[i] - 'a'];
        }
        return {row, sum == 100 ? sum : sum % 100};
    }
};