/*
 * @Descroption: LeetCode 1784. 检查二进制字符串字段
 * @Author: EmoryHuang
 * @Date: 2021-08-05 20:01:25
 * @Method:
 * 简单题，记录数字变化的次数
 */

class Solution {
   public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        for (int i = 1; i < s.size(); i++)
            if (s[i] != s[i - 1]) cnt++;
        return cnt <= 1;
    }
};