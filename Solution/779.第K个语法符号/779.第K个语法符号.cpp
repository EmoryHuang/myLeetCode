/*
 * @Descroption: LeetCode 779. ��K���﷨����
 * @Author: EmoryHuang
 * @Date: 2021-09-15 20:07:47
 * @Method:
 * �ݹ�
 * ÿһ�еĺ�벿��������ǰ�벿�ֵķ�ת
 */

class Solution {
   public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        if (k <= pow(2, n - 2)) return kthGrammar(n - 1, k);
        return kthGrammar(n - 1, k - pow(2, n - 2)) ^ 1;
    }
};