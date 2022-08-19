/*
 * @Descroption: LeetCode 917. 仅仅反转字母
 * @Author: EmoryHuang
 * @Date: 2021-04-19 14:04:36
 * @解题思路:
 * 设置左右两个指针，跳过非字母的字符，交换指针所指的元素
 */

class Solution {
   public:
    string reverseOnlyLetters(string S) {
        int left = 0, right = S.size() - 1;
        while (left < right) {
            while (left < right && !isalpha(S[left])) left++;
            while (left < right && !isalpha(S[right])) right--;
            if (left < right) swap(S[left++], S[right--]);
        }
        return S;
    }
};