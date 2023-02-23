'''
Descroption: LeetCode 895. 最大频率栈
Author: EmoryHuang
Date: 2022-11-30 09:25:40
Method:
使用两个哈希表分别存储每个数字出现的频率以及每个频率的数字
'''


class FreqStack:
    def __init__(self):
        self.freq = defaultdict(int)
        self.group = defaultdict(list)
        self.maxFreq = 0

    def push(self, val: int) -> None:
        self.freq[val] += 1
        self.group[self.freq[val]].append(val)
        self.maxFreq = max(self.maxFreq, self.freq[val])

    def pop(self) -> int:
        val = self.group[self.maxFreq].pop()
        self.freq[val] -= 1
        if len(self.group[self.maxFreq]) == 0:
            self.maxFreq -= 1
        return val


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()