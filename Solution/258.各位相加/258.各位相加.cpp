/*
 * @Descroption: LeetCode 258. ��λ���
 * @Author: EmoryHuang
 * @Date: 2021-05-22 15:10:00
 * @����˼·:
 * ���⣬���numС��10�򷵻�
 * ����������λ�ϵ�����֮��
 */

class Solution {
   public:
    int addDigits(int num) {
        if (num < 10) return num;
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
    }
};