/*
 * @Descroption: LeetCode 1573. �ָ��ַ����ķ�����
 * @Author: EmoryHuang
 * @Date: 2021-08-14 14:43:40
 * @Method:
 * �������
 * �����ַ�����1��λ�ú�����
 * �� 1 ������Ϊ 0��˵��û�� 1����ô���ΪC(2,n-1)���� (n - 1) * (n - 2) / 2
 * ���򣬿���ÿ��������֮�����һ�� 1 �͵�һ�� 1 �ľ���
 * Ȼ������������ԭ�����
 */

class Solution {
   public:
    int numWays(string s) {
        vector<int> ones;
        int n = s.size();
        for (int i = 0; i < n; i++)
            if (s[i] == '1') ones.push_back(i);
        int cnt = ones.size();
        if (cnt % 3 != 0) return 0;
        if (cnt == 0) {
            long long ways = (long long)(n - 1) * (n - 2) / 2;
            return ways % 1000000007;
        } else {
            int ind1 = cnt / 3, ind2 = cnt / 3 * 2;
            int cnt1 = ones[ind1] - ones[ind1 - 1];
            int cnt2 = ones[ind2] - ones[ind2 - 1];
            long long ways = (long long)cnt1 * cnt2;
            return ways % 1000000007;
        }
    }
};