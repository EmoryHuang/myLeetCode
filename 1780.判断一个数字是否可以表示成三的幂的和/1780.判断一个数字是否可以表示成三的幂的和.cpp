/*
 * @Descroption: LeetCode 1780. �ж�һ�������Ƿ���Ա�ʾ�������ݵĺ�
 * @Author: EmoryHuang
 * @Date: 2021-04-21 15:26:36
 * @����˼·:
 * ���һ�����ֿ��Ա�ʾ�������ݵĺͣ���ô�������ת��Ϊ�����ƺ�����Ӧ��ֻ�� 0 �� 1
 */

class Solution {
   public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};