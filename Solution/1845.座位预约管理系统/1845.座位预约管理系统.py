'''
Descroption: LeetCode 1845. ��λԤԼ����ϵͳ
Author: EmoryHuang
Date: 2021-07-15 19:00:33
����˼·:
����С�Ѵ洢��λ��Ԥ��ʱ�����Ѷ�Ԫ�أ�ȡ��ʱ�����Ӧ��λ��
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
