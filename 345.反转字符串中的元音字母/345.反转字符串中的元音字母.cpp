/*
 * @Descroption: LeetCode 345. 反转字符串中的元音字母
 * @Author: EmoryHuang
 * @Date: 2021-05-06 20:01:36
 * @解题思路: 简单题，跳过非元音字母，设置双指针进行反转
 */

class Solution {
   public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        string str = "aeiouAEIOU";
        while (i < j) {
            while (i < j && str.find(s[i]) == string::npos) i++;
            while (i < j && str.find(s[j]) == string::npos) j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};