/*
 * @Descroption: LeetCode 709. 转换成小写字母
 * @Author: EmoryHuang
 * @Date: 2021-05-30 10:37:00
 * @解题思路:
 * 利用ASCII
 * 大写变小写、小写变大写：字符 ^= 32 （大写 ^= 32 相当于 +32，小写 ^= 32 相当于 -32）
 * 大写变小写、小写变小写：字符 |= 32 （大写 |= 32 就相当于+32，小写 |= 32 不变）
 * 大写变大写、小写变大写：字符 &= -33 （大写 ^= -33 不变，小写 ^= -33 相当于 -32）
 * 当然直接调用库函数更方便
 */

class Solution {
   public:
    string toLowerCase(string s) {
        for (auto &c : s)
            if (isalpha(c)) c |= 32;
        return s;
    }
};