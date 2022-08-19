'''
Descroption: LeetCode 1845. 座位预约管理系统
Author: EmoryHuang
Date: 2021-07-15 19:00:33
解题思路:
用最小堆存储座位，预定时弹出堆顶元素，取消时加入对应座位号
'''


class SeatManager:

    def __init__(self, n: int):
        self.seats = list(range(1, n + 1))

    def reserve(self) -> int:
        return heappop(self.seats)

    def unreserve(self, seatNumber: int) -> None:
        heappush(self.seats, seatNumber)

# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
