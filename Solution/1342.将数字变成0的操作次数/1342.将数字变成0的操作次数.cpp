/*
 * @Descroption: LeetCode 1342. �����ֱ�� 0 �Ĳ�������
 * @Author: EmoryHuang
 * @Date: 2021-07-25 14:30:53
 * @����˼·:
 * ���⣬���չ�ʽ����
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