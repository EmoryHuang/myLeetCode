'''
Descroption: LeetCode 1807. �滻�ַ����е���������
Author: EmoryHuang
Date: 2021-09-24 18:59:30
Method:
��ϣ��
�����ַ������������������ȡ key ����ȡ��Ӧ�� value
�� key ���������� ?
'''


class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        hash = defaultdict(str)
        for key, val in knowledge:
            hash[key] = val
        ans, i = [], 0
        while i < len(s):
            key = ''
            if s[i] == '(':
                i += 1
                while s[i] != ')':
                    key += s[i]
                    i += 1
                if key in hash:
                    ans.append(hash[key])
                else:
                    ans.append('?')
            elif s[i] != ')':
                ans.append(s[i])
            i += 1
        return ''.join(ans)
