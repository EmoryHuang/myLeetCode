/*
 * @Descroption: LeetCode 1052. ������������ϰ�
 * @Author: EmoryHuang
 * @Date: 2021-08-06 16:10:53
 * @Method:
 * ��������
 * �����ų���������ʱ�Ĺ˿ͣ�ֻ��������ʱ�Ĺ˿�
 * ������СΪ minutes �Ļ������ڣ����㲻����ʱ�����˿���Ŀ
 */

class Solution {
   public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0, n = customers.size();
        // ���㲻����ʱ�Ĺ˿�����
        for (int i = 0; i < n; i++)
            if (grumpy[i] == 0) {
                ans += customers[i];
                customers[i] = 0;
            }
        // ��������
        int r = minutes, sumn = 0;
        for (int i = 0; i < r; i++) sumn += customers[i];
        int maxn = sumn;
        while (r < n) {
            sumn += customers[r];
            sumn -= customers[r - minutes];
            maxn = max(maxn, sumn);
            r++;
        }
        return ans + maxn;
    }
};