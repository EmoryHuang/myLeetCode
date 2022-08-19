/*
 * @Descroption: LeetCode 386. �ֵ�������
 * @Author: EmoryHuang
 * @Date: 2022-04-18 08:47:52
 * @Method:
 * dfs
 * ���ڵ�ǰ���� num
 * �� num * 10 <= n, ����һ������Ϊ num * 10
 * ���������ֵ, �� num % 10 == 9 or num + 1 > n, ���˻���һλ
 * ������һ������Ϊ num + 1
 */

class Solution {
   public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int num = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = num;
            if (num * 10 <= n)
                num *= 10;
            else {
                // �������ֵ�����˻���һλ
                while (num % 10 == 9 || num + 1 > n) {
                    num /= 10;
                }
                // ���û�е������ֵ����� 1
                num++;
            }
        }
        return ans;
    }
};