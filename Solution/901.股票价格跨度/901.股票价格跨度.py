'''
Descroption: LeetCode 901. 股票价格跨度
Author: EmoryHuang
Date: 2022-10-21 09:08:15
Method:
单调栈
使用单调栈存储天数及其价格，将栈中 <= price 的元素出栈
最终结果为当天时间 - 次大价格时的天数
'''


class StockSpanner:

    def __init__(self):
        self.st = [(0, inf)]
        self.day = 0

    def next(self, price: int) -> int:
        self.day += 1
        while price >= self.st[-1][1]:
            self.st.pop()
        self.st.append((self.day, price))
        return self.day - self.st[-2][0]


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)