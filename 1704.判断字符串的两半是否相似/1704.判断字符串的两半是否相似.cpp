/*
 * @Descroption: LeetCode 1704. 判断字符串的两半是否相似
 * @Author: EmoryHuang
 * @Date: 2021-05-19 20:03:31
 * @解题思路:
 * 遍历字符串，计数前半部分和后半部分的元音字母数量
 */

class Solution {
   public:
    bool halvesAreAlike(string s) {
        string str = "aeiouAEIOU";
        int flag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (str.find(s[i]) != string::npos) 
                flag = i < s.size() / 2 ? flag + 1 : flag - 1;
        }
        return flag == 0;
    }
};