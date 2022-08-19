'''
Descroption: LeetCode 1282. 用户分组
Author: EmoryHuang
Date: 2022-08-12 09:06:50
Method:
哈希表记录group大小相同用户的ID
之后贪心地对每个用户进行分组
'''


class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        hash = defaultdict(list)
        for i, size in enumerate(groupSizes):
            hash[size].append(i)
        res = []
        for size, group in hash.items():
            for i in range(0, len(group), size):
                res.append(group[i:i + size])
        return res