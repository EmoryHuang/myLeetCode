/*
 * @Descroption: LeetCode 504. 七进制数
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:51:36
 * @解题思路: 进制转换，整除求余
 */

class Solution {
   public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool flag = num < 0;
        num = num > 0 ? num : -num;
        string ans;
        while (num) {
            ans += num % 7 + '0';
            num /= 7;
        }
        if (flag) ans += "-";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};