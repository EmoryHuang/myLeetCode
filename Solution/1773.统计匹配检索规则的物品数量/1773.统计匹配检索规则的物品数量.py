'''
Descroption: LeetCode 1773. ͳ��ƥ������������Ʒ����
Author: EmoryHuang
Date: 2021-11-05 19:47:44
Method:
���⣬�����������ƥ��
'''


class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        if ruleKey == 'type':
            idx = 0
        elif ruleKey == 'color':
            idx = 1
        else:
            idx = 2
        ans = 0
        for item in items:
            if item[idx] == ruleValue:
                ans += 1
        return ans