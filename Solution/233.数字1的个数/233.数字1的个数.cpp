/*
 * @Descroption: LeetCode 233. ���� 1 �ĸ���
 * @Author: EmoryHuang
 * @Date: 2021-08-13 20:18:40
 * @Method:
 * �ֱ�������ʮ���١�ǧ...λ��1���ֵĴ���
 */

class Solution {
   public:
    int countDigitOne(int n) {
        // lowΪ��λ��curΪ��ǰλ��highΪ��λ
        int low = 0, cur = n % 10, high = n / 10;
        // baseΪ����
        long base = 1, ans = 0;
        while (high || cur) {
            if (cur == 0)
                // ��ǰλΪ 0����ôֻ�ܿ���λ����high��ȡ��
                ans += high * base;
            else if (cur == 1)
                // ��ǰλΪ 1���ڸ�λ�Ļ������ټ��ϵ�λ
                // ��Ϊ��ǰλΪ 1 �� low ����ʲô���֣������ 1 �й���
                ans += high * base + low + 1;
            else if (cur > 1)
                // ��ǰλ���� 1����ѵ�ǰλ����high
                ans += (high + 1) * base;
            low += base * cur;
            base *= 10;
            cur = high % 10;
            high /= 10;
        }
        return ans;
    }
};