'''
Descroption: LeetCode 1684. ͳ��һ���ַ�������Ŀ
Author: EmoryHuang
Date: 2021-09-22 16:32:12
Method:
���⣬�����ж�ÿ�������������ַ��Ƿ��� allowed ��
'''


class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        ans = 0
        for word in words:
            for c in word:
                if c not in allowed:
                    break
            else:
                ans += 1
        return ans