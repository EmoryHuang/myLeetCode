/*
 * @Descroption: LeetCode 1081. 不同字符的最小子序列
 * @Author: EmoryHuang
 * @Date: 2021-08-03 13:55:59
 * @Method:
 * 遍历字符，维护一个单调栈，
 * 若在该字符后面还有这个字符，则弹出，否则入栈
 */

class Solution {
   public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> hash;
        // 记录字符出现数量
        for (auto c : s) hash[c]++;
        string st;
        for (auto c : s) {
            // 如果当前字符不在栈中
            if (st.find(c) == string::npos) {
                // 维护一个单调栈
                // 若在该字符后面还有这个字符，则弹出
                while (!st.empty() && st.back() > c && hash[st.back()] > 0) st.pop_back();
                st.push_back(c);
            }
            hash[c]--;
        }
        return st;
    }
};