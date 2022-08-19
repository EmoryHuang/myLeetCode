/*
 * @Descroption: LeetCode 633. ƽ����֮��
 * @Author: EmoryHuang
 * @Date: 2021-04-28 13:44:36
 * @����˼·:
 * ����˫ָ�룬�ж�`a * a + b * b`��ֵ�����м��ƶ�
 */

class Solution {
   public:
    bool judgeSquareSum(int c) {
        long a = 0, b = sqrt(c);
        while (a <= b) {
            if (a * a + b * b == c)
                return true;
            else if (a * a + b * b > c)
                b--;
            else
                a++;
        }
        return false;
    }
};