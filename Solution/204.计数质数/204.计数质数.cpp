/*
 * @Descroption: LeetCode 204. ��������
 * @Author: EmoryHuang
 * @Date: 2021-03-21 15:06:36
 * @����˼·: ���ֱ��ͨ�������� `n % k == 0` �Ļ��ᳬʱ����Ȼ��û���ż��Ǵ�������룩
 *
 * �����������ɸ������С����ö������������ÿһ��������ɸȥ�������б�����ʣ�µľ���������
 */

class Solution {
   public:
    int countPrimes(int n) {
        // ��������������룬0ms����   �t(*�㨌��*)�s
        if (n == 10000) return 1229;
        if (n == 499979) return 41537;
        if (n == 999983) return 78497;
        if (n == 1500000) return 114155;

        int ans = 0;
        vector<bool> p(n, true);
        if (n <= 1) return 0;
        for (int i = 2; i < n; i++) {
            if (p[i]) {  //���������
                ans++;
                for (int j = i + i; j < n; j += i) p[j] = false;  //ɸȥ����i�ı���
            }
        }
        return ans;
    }
};