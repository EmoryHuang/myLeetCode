'''
Descroption: LeetCode 848. ��ĸ��λ
Author: EmoryHuang
Date: 2021-06-13 15:53:00
����˼·:
�����׺�ͣ�Ȼ��ͳһ��λ
'''


class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        for i in range(len(shifts) - 2, -1, -1):
            shifts[i] += shifts[i + 1] % 26
        ans = ""
        for i in range(len(s)):
            tmp = (ord(s[i]) - ord('a') + shifts[i]) % 26
            ans += chr(tmp + ord('a'))
        return ans
