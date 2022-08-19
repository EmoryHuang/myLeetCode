/*
 * @Descroption: LeetCode 191. λ 1 �ĸ���
 * @Author: EmoryHuang
 * @Date: 2021-03-21 14:13:36
 * @����˼·:
 * ����һ������ȡ�࣬`n % 2`
 *
 * ��������ֱ���ж����λ�����ǲ��� 1��ͨ�������㼴�� `n & 1`
 */

class Solution {
   public:
    // ����һ������ȡ��
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans += n % 2;
            n >>= 1;
        }
        return ans;
    }

    // ��������ֱ���ж����λ�����ǲ���1
    // int hammingWeight(uint32_t n) {
    //     int ans = 0;
    //     while (n) {
    //         ans += n & 1;
    //         n >>= 1;
    //     }
    //     return ans;
    // }
};