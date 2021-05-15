/*
 * @Descroption: LeetCode 1006. 笨阶乘
 * @Author: EmoryHuang
 * @Date: 2021-04-01 18:17:36
 * @解题思路:
 * 模拟的方法就是每 4 位累加
 *
 * 数学方法的证明可以参考
 * [官方题解](https://leetcode-cn.com/problems/clumsy-factorial/solution/ben-jie-cheng-by-leetcode-solution-deh2/)
 */

class Solution {
   public:
    // 方法一：模拟
    // int clumsy(int N) {
    //     if (N <= 2) return N;
    //     if (N == 3) return 6;
    //     int sum = N * (N - 1) / (N - 2) + N - 3;
    //     N -= 4;
    //     while (N >= 4) {
    //         sum += -N * (N - 1) / (N - 2) + N - 3;  //每4位累加
    //         N -= 4;
    //     }
    //     return sum - clumsy(N);  //加上不足4位的部分
    // }

    // 方法二：数学
    int clumsy(int N) {
        if (N == 1) {
            return 1;
        } else if (N == 2) {
            return 2;
        } else if (N == 3) {
            return 6;
        } else if (N == 4) {
            return 7;
        }
        if (N % 4 == 0) {
            return N + 1;
        } else if (N % 4 <= 2) {
            return N + 2;
        } else {
            return N - 1;
        }
    }
};