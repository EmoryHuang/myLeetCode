'''
Descroption: LeetCode 622. 设计循环队列
Author: EmoryHuang
Date: 2022-08-03 09:15:21
Method:
数组模拟队列
标记队列的头尾
'''


class MyCircularQueue:
    def __init__(self, k: int):
        self.front = self.rear = 0
        self.elements = [0] * (k + 1)

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.elements[self.rear] = value
        self.rear = (self.rear + 1) % len(self.elements)
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % len(self.elements)
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.elements[self.front]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.elements[(self.rear - 1) % len(self.elements)]

    def isEmpty(self) -> bool:
        return self.front == self.rear

    def isFull(self) -> bool:
        return (self.rear + 1) % len(self.elements) == self.front


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()