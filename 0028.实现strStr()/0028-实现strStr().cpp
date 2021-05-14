/*
 * @Descroption: LeetCode 28. ʵ�� strStr ()
 * @Author: EmoryHuang
 * @Date: 2021-03-19 20:13:36
 * @����˼·: �о����ѿɼ򵥣�����ֱ���ñ���ƥ�䣬���Ե����������� KMP �㷨
 */

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        if (len2 == 0) return 0;
        for (int i = 0; i < len1 - len2 + 1; i++) {
            if (haystack.substr(i, len2) == needle) {
                return i;
            }
        }
        return -1;
    }
};