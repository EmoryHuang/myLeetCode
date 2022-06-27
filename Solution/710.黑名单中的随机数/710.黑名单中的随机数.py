'''
Descroption: LeetCode 710. 黑名单中的随机数
Author: EmoryHuang
Date: 2022-06-25 10:59:54
Method:
对于在 [0,n-m) 范围内的黑名单数，可以将其映射到 [n-m,n) 范围内的非黑名单数（白名单数）上
'''


class Solution:
    def __init__(self, n: int, blacklist: List[int]):
        # 分界点
        self.seq = w = n - len(blacklist)
        # 分界点后的黑名单数字
        black = {b for b in blacklist if b >= self.seq}
        # 黑名单到白名单的映射
        self.b2w = {}
        # 对于分界点之前的黑名单数字，将其映射到分界点后非黑名单的数字
        for b in blacklist:
            if b < self.seq:
                while w in black:
                    w += 1
                self.b2w[b] = w
                w += 1

    def pick(self) -> int:
        x = random.randrange(self.seq)
        return self.b2w.get(x, x)


# Your Solution object will be instantiated and called as such:
# obj = Solution(n, blacklist)
# param_1 = obj.pick()