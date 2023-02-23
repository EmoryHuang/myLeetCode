/*
 * @Descroption: LeetCode 1945. 字符串转化后的各位数字之和
 * @Author: EmoryHuang
 * @Date: 2021-11-08 10:58:50
 * @Method:
 * 简单题，将字符串转化为数字，然后重复 k 次操作得到各位数字之和
 */

class Solution {
   public:
    int getLucky(string s, int k) {
        string ans = "";
        for (char c : s) ans += to_string(c - 'a' + 1);
        while (k--) {
            int sum = 0;
            for (char c : ans) sum += c - '0';
            ans = to_string(sum);
        }
        return stoi(ans);
    }
};