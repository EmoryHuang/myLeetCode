/*
 * @Descroption: ������ 16.01. ��������
 * @Author: EmoryHuang
 * @Date: 2021-07-18 14:29:38
 * @����˼·:
 * ��Ϊֻ����������������ʵ����ֱ�ӽ�������
 * ���x ^ 0 = x, x ^ x = 0
 */

class Solution {
   public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] = numbers[0] ^ numbers[1];
        numbers[1] = numbers[0] ^ numbers[1];
        numbers[0] = numbers[0] ^ numbers[1];
        return numbers;
    }
};