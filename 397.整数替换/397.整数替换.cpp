/*
 * @Descroption: LeetCode 397. �����滻
 * @Author: EmoryHuang
 * @Date: 2021-05-07 20:12:36
 * @����˼·:
 * ���⣬ֱ���õݹ�������
 */

class Solution {
   public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n == INT_MAX) return 32;  // �����
        if (n % 2 == 0)
            return 1 + integerReplacement(n / 2);
        else
            return 1 + min(integerReplacement(n + 1), integerReplacement(n - 1));
    }
};