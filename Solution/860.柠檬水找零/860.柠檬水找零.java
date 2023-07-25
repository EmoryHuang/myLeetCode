/*
 * @Descroption: LeetCode 860. 柠檬水找零
 * @Author: EmoryHuang
 * @Date: 2023-07-22 09:23:40
 * @Method:
 * 位运算
 */

import java.util.*;

class Solution {
    public boolean lemonadeChange(int[] bills) {
        int cnt5 = 0, cnt10 = 0, cnt20 = 0;
        for (int num : bills) {
            if (num == 5) {
                cnt5++;
            } else if (num == 10) {
                if (cnt5 == 0) {
                    return false;
                }
                cnt10++;
                cnt5--;
            } else if (num == 20) {
                if (cnt5 > 0 && cnt10 > 0) {
                    cnt5--;
                    cnt10--;
                } else if (cnt5 >= 3) {
                    cnt5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}