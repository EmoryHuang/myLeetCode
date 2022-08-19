/*
 * @Descroption: LeetCode 650. ֻ���������ļ���
 * @Author: EmoryHuang
 * @Date: 2021-09-19 14:27:58
 * @Method:
 * ��ѧ/��̬�滮
 * ��� n ��һ����������ô��������������
 * ��� n ��һ�������������ֽ��������ֽ�
 */

class Solution {
   public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                ans += i;
                n /= i;
            }
        }
        return ans;
    }
};