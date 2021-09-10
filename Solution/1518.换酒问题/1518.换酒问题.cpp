/*
 * @Descroption: LeetCode 1518. ��������
 * @Author: EmoryHuang
 * @Date: 2021-08-11 15:21:19
 * @Method:
 * ���⣬��ƿ���ɿ�ƿ
 */

class Solution {
   public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        while (empty >= numExchange) {
            numBottles += empty / numExchange;
            empty = empty % numExchange + empty / numExchange;
        }
        return numBottles;
    }
};