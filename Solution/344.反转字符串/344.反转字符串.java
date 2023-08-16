/*
 * @Description: LeetCode 344. 反转字符串
 * @Author: EmoryHuang
 * @Date: 2023-08-07 09:31:40
 * @Method:
 * 数组原地翻转
 */

import java.util.*;

class Solution {
    public void reverseString(char[] s) {
        int l = 0, r = s.length - 1;
        while (l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
}