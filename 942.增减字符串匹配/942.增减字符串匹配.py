'''
Descroption: LeetCode 942. �����ַ���ƥ��
Author: EmoryHuang
Date: 2021-06-04 14:03:00
����˼·:
ά����ǰδʹ�õ���С������������������ɨ���ַ�����
������� 'I'����ȡ����ǰ��С����������ȡ����ǰ������
'''


class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        low, high = 0, len(s)
        ans = []
        for c in s:
            if c == 'I':
                ans.append(low)
                low += 1
            elif c == 'D':
                ans.append(high)
                high -= 1
        ans.append(low)
        return ans
