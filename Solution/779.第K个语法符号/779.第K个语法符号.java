/*
 * @Descroption: LeetCode 779. 第K个语法符号
 * @Author: EmoryHuang
 * @Date: 2022-10-20 09:04:20
 * @Method:
 * 递归
 * 每一行的后半部分正好是前半部分的翻转
 */

class Solution {
    public int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;
        if (k <= Math.pow(2, n - 2))
            return kthGrammar(n - 1, k);
        return kthGrammar(n - 1, k - (int)Math.pow(2, n - 2)) ^ 1;
    }
}