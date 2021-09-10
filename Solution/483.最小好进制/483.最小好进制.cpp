/*
 * @Descroption: LeetCode 483. ��С�ý���
 * @Author: EmoryHuang
 * @Date: 2021-06-18 17:20:00
 * @����˼·:
 * �� n �� k ���Ƴ���Ϊ len����ô�� (n)10 = (11..1)k = k^0 + k^1 + ... + k^(len-1)
 * len = 1 ʱ, k^0 = 1, n = 1, �����ⲻ��;
 * len = 2 ʱ, k^0 + k^1 = n, k = n - 1 �� 2
 * ��� len �� 2
 * �� s = len - 1
 * ���ݶ���ʽ������з��������Եõ���k^s < n < (k+1)^s
 * �� k < n^(1/s) < k+1
 * ����ֻ��Ҫ��֤ n^(1/s) �Ƿ�Ϊ���������ɡ�
 */

class Solution {
   public:
    // ��ѧ����
    string smallestGoodBase(string n) {
        long num = stol(n);
        int max = (int)(log(num) / log(2) + 1);
        for (int len = max; len > 2; len--) {
            // k < n^(1/s) < k+1
            long k = powl(num, 1.0 / (len - 1));
            long ans = 0;
            // ��� len �� 1 �Ƿ�Ϊ n
            for (int i = 0; i < len; i++) ans = ans * k + 1;
            if (ans == num) return to_string(k);
        }
        return to_string(num - 1);
    }
};