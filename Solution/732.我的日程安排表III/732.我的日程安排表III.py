'''
Descroption: LeetCode 732. 我的日程安排表 III
Author: EmoryHuang
Date: 2022-06-06 09:20:54
Method:
线段树模板题
更多内容可见：https://emoryhuang.cn/blog/3153814731.html
'''


class SegmentTree:
    class Node:
        def __init__(self):
            self.left = None
            self.right = None
            self.val = 0
            self.lazy = 0

    def __init__(self):
        self.root = self.Node()

    @staticmethod
    def query(start, end, node, left, right):
        if left <= start and end <= right:
            return node.val

        mid, sum = start + ((end - start) >> 1), 0
        SegmentTree.pushdown(node)
        if left <= mid:
            sum = SegmentTree.query(start, mid, node.left, left, right)
        if right > mid:
            sum = max(sum, SegmentTree.query(mid + 1, end, node.right, left, right))
        return sum

    @staticmethod
    def update(start, end, node, left, right, val):
        if left <= start and end <= right:
            node.val += val
            node.lazy += val
            return

        mid = start + ((end - start) >> 1)
        SegmentTree.pushdown(node)
        if left <= mid:
            SegmentTree.update(start, mid, node.left, left, right, val)
        if right > mid:
            SegmentTree.update(mid + 1, end, node.right, left, right, val)
        SegmentTree.pushup(node)

    @staticmethod
    def pushup(node):
        node.val = max(node.left.val, node.right.val)

    @staticmethod
    def pushdown(node):
        if node.left is None:
            node.left = SegmentTree.Node()
        if node.right is None:
            node.right = SegmentTree.Node()
        if node.lazy:
            node.left.val += node.lazy
            node.right.val += node.lazy
            node.left.lazy += node.lazy
            node.right.lazy += node.lazy
            node.lazy = 0


class MyCalendarThree:
    def __init__(self):
        self.tree = SegmentTree()

    def book(self, start: int, end: int) -> int:
        self.tree.update(0, int(1e9), self.tree.root, start, end - 1, 1)
        return self.tree.query(0, int(1e9), self.tree.root, 0, int(1e9))


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)