'''
Descroption: LeetCode 2034. 股票价格波动
Author: EmoryHuang
Date: 2022-01-23 09:05:05
Method:
模拟
使用哈希表存储时间价格
'''

from sortedcontainers import SortedList


class StockPrice:
    def __init__(self):
        self.prices = SortedList()
        self.map = {}
        self.max_t = 0

    def update(self, timestamp: int, price: int) -> None:
        if timestamp in self.map:
            self.prices.remove(self.map[timestamp])
        self.prices.add(price)
        self.map[timestamp] = price
        self.max_t = max(self.max_t, timestamp)

    def current(self) -> int:
        return self.map[self.max_t]

    def maximum(self) -> int:
        return self.prices[-1]

    def minimum(self) -> int:
        return self.prices[0]


# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()