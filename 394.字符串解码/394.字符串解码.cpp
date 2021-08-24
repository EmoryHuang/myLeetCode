/*
 * @Descroption: LeetCode 394. 字符串解码
 * @Author: EmoryHuang
 * @Date: 2021-08-24 16:23:43
 * @Method:
 * 使用栈记录 '[' 前的情况，前面的结果以及重复数字
 * 如果遇到 '[' 则将前面的结果以及重复数字入栈
 * 如果遇到 ']' 则进行重复
 */

class Solution {
   public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        int num = 0;
        string ans;
        for (auto c : s) {
            if (isdigit(c))
                num = num * 10 + c - '0';
            else if (c == '[') {
                st.push({ans, num});
                ans.clear();
                num = 0;
            } else if (c == ']') {
                auto top = st.top();
                st.pop();
                string tmp;
                while (top.second--) tmp += ans;
                ans = top.first + tmp;
            } else
                ans += c;
        }
        return ans;
    }
};