/*
 * @Descroption: LeetCode 1952. 三除数
 * @Author: EmoryHuang
 * @Date: 2021-08-23 19:14:36
 * @Method:
 * 简单题，遍历判断除数个数
 */

class Solution {
   public:
    bool isThree(int n) {
        int ans = 0;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) ans += 2;
            if (i * i == n) ans -= 1;
        }
        return ans == 3;
    }
};