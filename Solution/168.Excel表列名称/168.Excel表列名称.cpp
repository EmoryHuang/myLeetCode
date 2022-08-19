/*
 * @Descroption: LeetCode 168. Excel 表列名称
 * @Author: EmoryHuang
 * @Date: 2021-04-20 16:02:36
 * @解题思路: 将数字转化为字符，整除取余，通过 string 拼接
 */

class Solution {
   public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            columnNumber--;
            ans = (char)(columnNumber % 26 + 65) + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};