/*
 * @Descroption: LeetCode 693. ����λ��������
 * @Author: EmoryHuang
 * @Date: 2021-05-01 20:20:36
 * @����˼·:
 * ���αȽϺ���λ���Ƿ���ȣ���������򷵻� `false`
 */

class Solution {
   public:
    bool hasAlternatingBits(int n) {
        while (n) {
            if ((n & 1) == ((n >> 1) & 1)) return false;
            n >>= 1;
        }
        return true;
    }
};