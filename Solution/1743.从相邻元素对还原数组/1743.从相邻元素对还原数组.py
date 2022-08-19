'''
Descroption: LeetCode 1743. 从相邻元素对还原数组
Author: EmoryHuang
Date: 2021-07-25 13:24:13
Method:
使用哈希表存储相邻元素
其中，首尾元素只会出现一次，因此，只需要先找出首尾元素
然后按照相邻元素寻找即可
'''


class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        hash = defaultdict(list)
        for a, b in adjacentPairs:
            hash[a].append(b)
            hash[b].append(a)
        ans = []
        n = len(adjacentPairs) + 1
        for key, value in hash.items():
            # 首尾元素只出现一次
            if len(value) == 1:
                # 加入首元素和相邻的元素
                ans.append(key)
                ans.append(value[0])
                break
        for i in range(2, n):
            next = hash[ans[i - 1]]  # 上一个元素的相邻元素
            if next[0] == ans[i - 2]:
                ans.append(next[1])
            else:
                ans.append(next[0])
        return ans