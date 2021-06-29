'''
Descroption: 剑指 Offer 09. 用两个栈实现队列
Author: EmoryHuang
Date: 2021-06-29 19:51:00
解题思路:
使用两个栈，一个栈入，一个栈出
进入元素时，将元素放入 s_in
删除元素时，
    若 s_out 非空，则弹出s_out，
    若 s_out 为空，则把 s_in 中的东西全部放入 s_out 中，弹出s_out，
    若 s_out, s_in 都为空，返回 -1
'''


class CQueue:

    def __init__(self):
        self.s_in = []
        self.s_out = []

    def appendTail(self, value: int) -> None:
        self.s_in.append(value)

    def deleteHead(self) -> int:
        if not self.s_out:  # 若 s_out 为空
            if not self.s_in:  # 若 s_in 为空
                return -1
            while self.s_in:  # 把 s_in 中的东西全部放入 s_out 中
                self.s_out.append(self.s_in.pop())
        return self.s_out.pop()

# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
