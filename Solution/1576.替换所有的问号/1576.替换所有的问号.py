'''
Descroption: LeetCode 1576. �滻���е��ʺ�
Author: EmoryHuang
Date: 2022-01-05 08:50:58
Method:
���⣬�����ʺ�ʱ��������ǰ�������ַ�
ֻҪȡ���ⲻͬ���ַ��Ϳ���
ͷβ���ʺű��⿼�Ǳ߽����
'''


class Solution:
    def modifyString(self, s: str) -> str:
        # ͷβ���ʺű��⿼�Ǳ߽����
        s = list("?" + s + "?")
        for i in range(1, len(s) - 1):
            if s[i] == "?":
                for j in range(97, 123):
                    if chr(j) != s[i + 1] and chr(j) != s[i - 1]:
                        s[i] = chr(j)
                        break
        return "".join(s[1:-1])
