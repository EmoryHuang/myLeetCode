'''
Descroption: LeetCode 933. 最近的请求次数
Author: EmoryHuang
Date: 2022-05-05 08:46:20
Method:
简单题，使用队列模拟
若队首元素超时，则删除队首元素
'''


class RecentCounter:
    def __init__(self):
        self.q = deque()

    def ping(self, t: int) -> int:
        self.q.append(t)
        while self.q[0] < t - 3000:
            self.q.popleft()
        return len(self.q)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)