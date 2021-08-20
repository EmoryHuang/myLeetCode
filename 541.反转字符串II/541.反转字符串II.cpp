/*
 * @Descroption: LeetCode 541. ��ת�ַ��� II
 * @Author: EmoryHuang
 * @Date: 2021-08-20 15:29:10
 * @Method:
 * ģ�⣬������ÿ�� 2k ���ַ���תǰ k ��
 */

class Solution {
   public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            int j = min(i + k, n);
            reverse(s.begin() + i, s.begin() + j);
        }
        return s;
    }
};