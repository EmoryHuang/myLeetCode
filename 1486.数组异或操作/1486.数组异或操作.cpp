/*
 * @Descroption: LeetCode 1486. ����������
 * @Author: EmoryHuang
 * @Date: 2021-05-07 19:14:36
 * @����˼·:
 * ���⣬����򶼲���Ҫ�˽�
 */

class Solution {
   public:
    int xorOperation(int n, int start) {
        int ans = start;
        for (int i = 1; i < n; i++) ans ^= start + 2 * i;
        return ans;
    }
};