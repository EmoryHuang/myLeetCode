/*
 * @Descroption: LeetCode 8. 字符串转换整数 (atoi)
 * @Author: EmoryHuang
 * @Date: 2021-03-18 14:30:36
 * @解题思路: 根据转换的规则来，首先去除字符串前面多余的0，
 * 之后判断正负，接着读取数字，直到不是数字为止
 */

class Solution {
   public:
    int myAtoi(string s) {
        int len = s.size();
        int flag = 1, i = 0;
        long ans = 0;
        while (s[i] == ' ') i++;     //去除前面多余的空格
        if (s[i] == '-') flag = -1;  //判断正负
        if (s[i] == '-' || s[i] == '+') i++;
        while (i < len && isdigit(s[i])) {
            int temp = s[i] - '0';
            ans = ans * 10 + temp;
            i++;
            if (ans > INT_MAX) {  //判断是否越界
                return flag == 1 ? INT_MAX : INT_MIN;
            }
        }
        return ans * flag;
    }
};