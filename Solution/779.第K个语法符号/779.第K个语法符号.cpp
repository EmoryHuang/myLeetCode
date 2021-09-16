/*
 * @Descroption: LeetCode 779. 第K个语法符号
 * @Author: EmoryHuang
 * @Date: 2021-09-15 20:07:47
 * @Method:
 * 递归
 * 每一行的后半部分正好是前半部分的翻转
 */

class Solution {
   public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        if (k <= pow(2, n - 2)) return kthGrammar(n - 1, k);
        return kthGrammar(n - 1, k - pow(2, n - 2)) ^ 1;
    }
};