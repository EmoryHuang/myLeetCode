'''
Descroption: LeetCode 677. 键值映射
Author: EmoryHuang
Date: 2021-11-14 14:17:50
Method:
哈希表记录所有字符串
求和时遍历哈希表, 使用正则匹配
'''


class MapSum:
    def __init__(self):
        self.hash = defaultdict(int)

    def insert(self, key: str, val: int) -> None:
        self.hash[key] = val

    def sum(self, prefix: str) -> int:
        ans = 0
        for key, val in self.hash.items():
            if re.match(prefix, key):
                ans += val
        return ans


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)