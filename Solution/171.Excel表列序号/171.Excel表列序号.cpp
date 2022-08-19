/*
 * @Descroption: LeetCode 171. Excel 表列序号
 * @Author: EmoryHuang
 * @Date: 2021-04-20 16:25:36
 * @解题思路: 与[170. Excel 表列名称]相反，26 进制数转 10 进制
 */

class Solution {
   public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.size();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans = ans * 26 + (columnTitle[i] - 'A' + 1);
        }
        return ans;
    }
};