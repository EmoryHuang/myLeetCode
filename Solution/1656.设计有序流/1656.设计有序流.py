'''
Descroption: LeetCode 1656. 设计有序流
Author: EmoryHuang
Date: 2022-08-16 09:08:18
Method:
数组存储有序流，并维护当前指针
'''


class OrderedStream:
    def __init__(self, n: int):
        self.n = n
        self.stream = [None] * n
        self.idx = 0

    def insert(self, idKey: int, value: str) -> List[str]:
        self.stream[idKey - 1] = value
        res = []
        while self.idx < self.n and self.stream[self.idx] is not None:
            self.idx += 1
            res.append(self.stream[self.idx - 1])
        return res


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)