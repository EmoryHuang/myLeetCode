'''
Descroption: LeetCode 524. ͨ��ɾ����ĸƥ�䵽�ֵ��������
Author: EmoryHuang
Date: 2021-09-14 11:24:30
Method:
˫ָ�� + ����
p, q �ֱ�Ϊָ�� s �� word ��ָ��
���ַ���ȣ���p��q�����ƶ�������p�����ƶ�
����ҵ���һ���ַ���������� ans
�����Ⱥ��ֵ������� ans
'''


class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        ans = []
        for word in dictionary:
            # p, q �ֱ�Ϊָ�� s �� word ��ָ��
            p, q = 0, 0
            while p < len(s) and q < len(word):
                if s[p] == word[q]:
                    p, q = p + 1, q + 1
                else:
                    p += 1
                # ����ҵ���һ���ַ���
                if q == len(word):
                    ans.append(word)
                    break
        if not ans:
            return ''
        # �����Ⱥ��ֵ�������
        ans.sort(key=lambda x: [-len(x), x])
        return ans[0]
