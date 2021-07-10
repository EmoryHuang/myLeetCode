'''
Descroption: LeetCode 981. 基于时间的键值存储
Author: EmoryHuang
Date: 2021-07-10 13:51:58
解题思路:
哈希表 + 二分
使用哈希表存储 key, value, timestamp
针对需要查找的 key, 使用二分搜索查找小于等于 timestamp 的第一个值
'''


class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.mp = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.mp[key].append((value, timestamp))

    def get(self, key: str, timestamp: int) -> str:
        ls = self.mp[key]
        if not ls:  # 如果不存在这个键值
            return ""
        l, r = 0, len(ls) - 1
        while l < r:
            mid = (l + r + 1) // 2
            if ls[mid][1] <= timestamp:
                l = mid
            else:
                r = mid - 1
        if ls[r][1] > timestamp:
            return ""
        return ls[r][0]

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
