/*
 * @Descroption: LeetCode 869. ��������õ� 2 ����
 * @Author: EmoryHuang
 * @Date: 2021-10-28 09:05:18
 * @Method:
 * ���ö�ٳ� 1e9 ������ 2 ����
 * ͳ�� n �и������ֵĸ���
 * Ȼ��������� 2 �������Ƿ����һ���������������ֵĸ����� n ��ͬ
 */

class Solution {
   public:
    bool reorderedPowerOf2(int n) {
        vector<int> power, cnt(10);
        for (int i = 1; i < 1e9; i *= 2) power.push_back(i);
        while (n) {
            cnt[n % 10]++;
            n /= 10;
        }
        for (int num : power) {
            bool flag = true;
            vector<int> cur(10);
            while (num) {
                cur[num % 10]++;
                num /= 10;
            }
            for (int i = 0; i < 10; i++)
                if (cur[i] != cnt[i]) {
                    flag = false;
                    break;
                }
            if (flag) return true;
        }
        return false;
    }
};