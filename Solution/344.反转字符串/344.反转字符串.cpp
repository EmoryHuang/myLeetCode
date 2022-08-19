/*
 * @Descroption: LeetCode 344. 反转字符串
 * @Author: EmoryHuang
 * @Date: 2021-05-06 20:13:36
 * @解题思路: 简单题，设置双指针，从前往后，从后往前移动
 */

class Solution {
   public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};