/*
 * @Descroption: LeetCode 461. ��������
 * @Author: EmoryHuang
 * @Date: 2021-05-27 19:48:17
 * @����˼·:
 * ��� d �����λ��������λΪ 1����ô���������һ��Ȼ���� d ��������һλ
 */

class Solution {
   public:
    int hammingDistance(int x, int y) {
        int d = x ^ y;
        int ans = 0;
        while (d) {
            ans += d & 1;
            d >>= 1;
        }
        return ans;
    }
};