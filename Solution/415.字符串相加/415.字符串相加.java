/*
 * @Descroption: LeetCode 415. 字符串相加
 * @Author: EmoryHuang
 * @Date: 2023-07-17 09:45:05
 * @Method:
 * 大数加法，维护进位
 */

import java.util.*;

class Solution {
    public String addStrings(String num1, String num2) {
        int i = num1.length() - 1, j = num2.length() - 1;
        int cur = 0;
        StringBuilder ans = new StringBuilder();
        while (i >= 0 || j >= 0 || cur != 0) {
            if (i >= 0) {
                cur += num1.charAt(i) - '0';
            }
            if (j >= 0) {
                cur += num2.charAt(j) - '0';
            }
            ans.append(cur % 10);
            cur /= 10;
            i--;
            j--;
        }
        return ans.reverse().toString();
    }
}