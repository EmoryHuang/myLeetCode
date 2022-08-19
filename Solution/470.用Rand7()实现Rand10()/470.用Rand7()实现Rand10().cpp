/*
 * @Descroption: LeetCode 470. 用 Rand7() 实现 Rand10()
 * @Author: EmoryHuang
 * @Date: 2021-09-05 19:52:50
 * @Method:
 * 调用两次 rand7()，可以得到 [1, 49]
 * 由于我们只需要 [1, 10]，那么可以考虑使用 [1, 40]
 * 每个数生成的概率为 4/49
 */

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
   public:
    int rand10() {
        while (1) {
            int row = rand7();
            int col = rand7();
            int ind = (row - 1) * 7 + col;
            if (ind <= 40) {
                return 1 + (ind - 1) % 10;
            }
        }
        return 0;
    }
};