/*
 * @Descroption: LeetCode 678. 有效的括号字符串
 * @Author: EmoryHuang
 * @Date: 2021-09-12 15:09:30
 * @Method:
 * 模拟
 * 令左括号的得分为 1；右括号的得分为 -1
 * l, r 分别表示的最小得分和最大得分
 * 遍历字符串，若当前字符为 ( 或 ) ，l和r同时 +1 / -1
 * 若当前字符为 * 可能是左括号或者右括号，那么总的来说 l - 1，r + 1
 * 对于合法的方案而言，必定满足最终得分为 0
 */

class Solution {
   public:
    bool checkValidString(string s) {
        // 令左括号的得分为 1；右括号的得分为 -1
        // l, r 分别表示的最小得分和最大得分
        int l = 0, r = 0;
        for (auto c : s) {
            if (c == '(')  // 左括号
                l++, r++;
            else if (c == ')')  // 右括号
                l--, r--;
            else if (c == '*')
                // * 可能是左括号或者右括号, 那么总的来说 l - 1，r + 1
                l--, r++;
            l = max(0, l);
            if (l > r) return false;  // 右括号太多
        }
        return l == 0;
    }
};