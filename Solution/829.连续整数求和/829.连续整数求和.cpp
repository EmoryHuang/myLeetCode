/*
 * @Descroption: LeetCode 829. �����������
 * @Author: EmoryHuang
 * @Date: 2022-06-03 10:50:20
 * @Method:
 * ����ĳ����������Ϊa������Ϊk����Ϊn����ô���ݵȲ����������:
 * n = (2a + k - 1) * k / 2
 * a = (2n / k - k + 1) / 2
 * ��Ϊ a �� 1
 * ���� n = (2a + k - 1) * k / 2 �� (k + 1) * k / 2 �� k^2 / 2
 * ���� k �� ��(2n)
 */


class Solution {
   public:
    int consecutiveNumbersSum(int _n) {
        int ans = 0, n = _n * 2;
        for (int k = 1; k * k < n; ++k) {
            // �� 2n = (2a + k - 1) * k ֪ 2n �ض����� k
            if (n % k != 0) continue;
            if ((n / k - k + 1) % 2 == 0) ans++;
        }
        return ans;
    }
};