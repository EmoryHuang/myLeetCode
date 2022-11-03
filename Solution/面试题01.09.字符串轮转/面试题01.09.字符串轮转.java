/*
 * @Descroption: LeetCode 面试题 01.09. 字符串轮转
 * @Author: EmoryHuang
 * @Date: 2022-09-29 10:04:52
 * @Method:
 * 先检查长度是否相等
 * 由于是旋转结构对s2进行收尾拼接，检查是否包含s1
 */

class Solution {
    public boolean isFlipedString(String s1, String s2) {
        if (s1.length() != s2.length())
            return false;
        return (s2 + s2).contains(s1);
    }
}