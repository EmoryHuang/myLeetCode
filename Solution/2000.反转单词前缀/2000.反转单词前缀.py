'''
Descroption: LeetCode 2000. ��ת����ǰ׺
Author: EmoryHuang
Date: 2022-02-02 20:14:25
Method:
���⣬�ҵ�ָ���ַ���תǰ����ַ���
'''


class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        i = word.find(ch) + 1
        return word[:i][::-1] + word[i:]
