/*
 * @Descroption: LeetCode 1342. 将数字变成 0 的操作次数
 * @Author: EmoryHuang
 * @Date: 2021-07-25 14:30:53
 * @解题思路:
 * 简单题，按照公式计算
 */

class Solution {
   public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while (num) {
            if (num % 2 == 0)
                num /= 2;
            else
                num--;
            cnt++;
        }
        return cnt;
    }
};