/*
 * @Descroption: LeetCode 917. ������ת��ĸ
 * @Author: EmoryHuang
 * @Date: 2021-04-19 14:04:36
 * @����˼·:
 * ������������ָ�룬��������ĸ���ַ�������ָ����ָ��Ԫ��
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