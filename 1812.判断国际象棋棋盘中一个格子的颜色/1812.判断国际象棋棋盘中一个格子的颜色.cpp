/*
 * @Descroption: LeetCode 1812. �жϹ�������������һ�����ӵ���ɫ
 * @Author: EmoryHuang
 * @Date: 2021-06-16 15:52:00
 * @����˼·:
 * ���⣬������������Ϊ���������ǰ�ɫ������Ϊ��
 */

class Solution {
   public:
    bool squareIsWhite(string coordinates) {
        int ind = coordinates[0] + coordinates[1];
        return ind % 2 == 1;
    }
};