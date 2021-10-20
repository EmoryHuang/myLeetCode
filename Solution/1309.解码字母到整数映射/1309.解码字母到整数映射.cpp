/*
 * @Descroption: LeetCode 1309. 解码字母到整数映射
 * @Author: EmoryHuang
 * @Date: 2021-10-20 09:05:09
 * @Method:
 * 简单题，倒序遍历，将整数转为字母
 */

class Solution {
   public:
    string freqAlphabets(string s) {
        string ans;
        char c;
        int idx = s.size() - 1;
        while (idx >= 0) {
            if (s[idx] == '#') {
                c = stoi(s.substr(idx - 2, 2)) + 'a' - 1;
                idx -= 2;
            } else
                c = s[idx] - '0' + 'a' - 1;
            ans += c;
            idx--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};