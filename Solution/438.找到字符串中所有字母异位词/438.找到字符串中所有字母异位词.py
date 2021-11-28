'''
Descroption: LeetCode 438. �ҵ��ַ�����������ĸ��λ��
Author: EmoryHuang
Date: 2021-11-28 18:48:25
Method:
��������
�Ƚϻ��������еĴ�Ƶ���ַ����еĴ�Ƶ�Ƿ�һ��
��Ƶ�������˵������
'''


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        sl, pl = len(s), len(p)
        cnts, cntp = [0] * 26, [0] * 26
        for i in range(pl):
            cntp[ord(p[i]) - ord('a')] += 1
        l, ans = 0, []
        for r in range(sl):
            cnts[ord(s[r]) - ord('a')] += 1
            if r - l + 1 > pl:
                cnts[ord(s[l]) - ord('a')] -= 1
                l += 1
            if cnts == cntp:
                ans.append(l)
        return ans
