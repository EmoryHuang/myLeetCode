'''
Descroption: LeetCode 599. 两个列表的最小索引总和
Author: EmoryHuang
Date: 2022-03-14 08:50:20
Method:
简单题，使用哈希表记录 list1 每个元素的索引
然后在 list2 中寻找 list1 中的元素，并维护最小索引和
'''


class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        hash = defaultdict(list)
        for i, name in enumerate(list1):
            hash[name].append(i)
        ans = []
        min_idx = float('inf')
        for i, name in enumerate(list2):
            if name in hash:
                idx = hash[name][0] + i
                if idx < min_idx:
                    min_idx = idx
                    ans = [name]
                elif idx == min_idx:
                    ans.append(name)
        return ans