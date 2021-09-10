/*
 * @Descroption: LeetCode 190. �ߵ�������λ
 * @Author: EmoryHuang
 * @Date: 2021-03-29 19:30:36
 * @����˼·:
 * �� n ����һ����Ϊ 32 �Ķ����ƴ����ӵ�λ����λö�� n ��ÿһλ�����䵹����ӵ���ת��� ans ��
 */

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};