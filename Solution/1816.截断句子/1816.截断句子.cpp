/*
 * @Descroption: LeetCode 1816. �ضϾ���
 * @Author: EmoryHuang
 * @Date: 2021-06-16 15:27:00
 * @����˼·:
 * ���⣬���ո�
 */

class Solution {
   public:
    string truncateSentence(string s, int k) {
        string ans;
        for (auto c : s) {
            if (c == ' ') k--;
            if (k == 0) return ans;
            ans += c;
        }
        return ans;
    }
};