/*
 * @Descroption: LeetCode 1492. n �ĵ� k ������
 * @Author: EmoryHuang
 * @Date: 2021-04-21 15:53:36
 * @����˼·:
 * ���⣬���������ӣ����ص� k ������
 */

class Solution {
   public:
    int kthFactor(int n, int k) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) k--;
            if (k == 0) return i;
        }
        return -1;
    }
};