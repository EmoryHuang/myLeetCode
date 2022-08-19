'''
Descroption: LeetCode 1773. 统计匹配检索规则的物品数量
Author: EmoryHuang
Date: 2021-11-05 19:47:44
Method:
简单题，遍历数组进行匹配
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