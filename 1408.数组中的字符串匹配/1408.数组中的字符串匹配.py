'''
Descroption: LeetCode 1408. �����е��ַ���ƥ��
Author: EmoryHuang
Date: 2021-06-23 12:50:00
����˼·:
����������ÿ��Ԫ�أ�������Ԫ���в����Ƿ�Ϊ�Ӵ�
'''


class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = []
        for i, word in enumerate(words):
            if word in ' '.join(words[:i] + words[i + 1:]):
                ans.append(word)
        return ans
