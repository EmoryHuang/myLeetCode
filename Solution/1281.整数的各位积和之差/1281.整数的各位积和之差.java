/*
 * @Description: LeetCode 1281. 整数的各位积和之差
 * @Author: EmoryHuang
 * @Date: 2023-08-09 09:40:50
 * @Method:
 * 简单题，遍历各位数
 */

import java.util.*;

class Solution {
    public int subtractProductAndSum(int n) {
        int a = 0, b = 1;
        while (n != 0) {
            a += n % 10;
            b *= n % 10;
            n /= 10;
        }
        return b - a;
    }
}