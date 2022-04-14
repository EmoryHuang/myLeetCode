'''
Descroption: LeetCode 380. O(1) 时间插入、删除和获取随机元素
Author: EmoryHuang
Date: 2022-04-13 08:48:45
Method:
数组 + 哈希表
数组存储元素，哈希表存储对应的下标
删除操作时将变长数组的最后一个元素移动到待删除元素的下标处，然后删除变长数组的最后一个元素。
'''


class RandomizedSet:
    def __init__(self):
        self.nums = []
        self.hash = defaultdict(int)

    def insert(self, val: int) -> bool:
        if val in self.hash:
            return False
        self.hash[val] = len(self.nums)
        self.nums.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.hash:
            return False
        index = self.hash[val]
        self.nums[index] = self.nums[-1]
        self.hash[self.nums[index]] = index
        self.nums.pop()
        del self.hash[val]
        return True

    def getRandom(self) -> int:
        return choice(self.nums)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
