/*
 * @Descroption: LeetCode 65. 有效数字
 * @Author: EmoryHuang
 * @Date: 2021-06-16 13:21:00
 * @解题思路:
 * 模拟，分类讨论，判断是否符合条件
 */

class Solution {
   public:
    bool isNumber(string s) {
        bool hasNum = false, hasE = false, isFloat = false;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            // 符号位只能在首位或E的后一位
            if ((c == '+' || c == '-') && (i == 0 || s[i - 1] == 'E' || s[i - 1] == 'e'))
                ;
            // 只存在一个E, 前面必须有数字, 后面也必须有数字
            else if ((c == 'E' || c == 'e') && !hasE && hasNum) {
                hasE = true;
                hasNum = false;
            } else if (c == '.' && !isFloat && !hasE)
                //只存在一个小数点, 不能在E的后面
                isFloat = true;
            else if (isdigit(c))
                hasNum = true;
            else
                return false;
        }
        return hasNum;
    }
};