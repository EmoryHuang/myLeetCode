/*
 * @Descroption: LeetCode 38. 外观数列
 * @Author: EmoryHuang
 * @Date: 2021-05-10 10:28:36
 * @解题思路: 通过递归的方法，从第一项直到第 `n` 项，生成每项的外观数列，
 * 若 `pre[i] != pre[i + 1]` 则记录字符个数，数字，并将计数清 `0`。
 */

class Solution {
   public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ans, pre = countAndSay(n - 1);
        int c = 1;
        for (int i = 0; i < pre.size(); i++) {
            if (pre[i] != pre[i + 1]) {  // 字符串有终止符
                ans += (c + '0');        // 个数
                ans += pre[i];           // 数字
                c = 0;
            }
            c++;
        }
        return ans;
    }
};