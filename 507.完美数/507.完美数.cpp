/*
 * @Descroption: LeetCode 507. ������
 * @Author: EmoryHuang
 * @Date: 2021-03-25 14:05:36
 * @����˼·: ��ö��
 */

class Solution {
   public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) sum += i;
        }
        return sum == num;
    }
};