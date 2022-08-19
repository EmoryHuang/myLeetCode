/*
 * @Descroption: LeetCode 1556. 千位分隔数
 * @Author: EmoryHuang
 * @Date: 2021-08-14 14:07:11
 * @Method:
 * 遍历字符串，添加千位分隔数
 */

class Solution {
   public:
    string thousandSeparator(int n) {
        if (n < 1000) return to_string(n);
        string s = to_string(n);
        for (int i = s.size() - 3; i > 0; i -= 3) s.insert(s.begin() + i, '.');
        return s;
    }
};