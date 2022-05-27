'''
Descroption: LeetCode 699. 掉落的方块
Author: EmoryHuang
Date: 2022-05-26 21:01:40
Method:
方法一：暴力枚举
枚举每一个方块以及这个方块之前的方块，检查是否有重叠
如有重叠的更新最大高度

方法二：线段树
O(log(n))
'''


class Solution:
    # 方法一：暴力枚举
    # def fallingSquares(self, positions: List[List[int]]) -> List[int]:
    #     n = len(positions)
    #     height = [0] * n
    #     # 枚举每一个方块
    #     for i, (left, side) in enumerate(positions):
    #         right = left + side - 1
    #         height[i] = side
    #         # 枚举这个方块之前的方块，检查是否有重叠
    #         for j in range(i):
    #             left_pre = positions[j][0]
    #             right_pre = positions[j][0] + positions[j][1] - 1
    #             if left <= right_pre and left_pre <= right:
    #                 height[i] = max(height[i], height[j] + side)
    #     # 更新最大高度
    #     for i in range(1, n):
    #         height[i] = max(height[i], height[i - 1])
    #     return height

    # 方法二：线段树
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        ans, st, max_range = [], SegmentTree(), int(1e9)
        for a, length in positions:
            cur = SegmentTree.query(0, max_range, st.root, a, a + length - 1)
            SegmentTree.update(0, max_range, st.root, a, a + length - 1, cur + length)
            ans.append(st.root.val)
        return ans


class SegmentTree:
    class Node:
        def __init__(self):
            self.left = None
            self.right = None
            self.val = 0
            self.lazy = 0

    def __init__(self) -> None:
        self.root = self.Node()

    @staticmethod
    def query(start: int, end: int, node: Node, left: int, right: int) -> int:
        # [s, t] 为当前节点包含的区间, 当前根为 node
        # 查询 [left, right] 区间的结果

        # 当前区间为询问区间的子集时直接返回当前区间的和
        if left <= start and right >= end:
            return node.val
        SegmentTree.pushdown(node)
        mid, sum = start + ((end - start) >> 1), 0
        if left <= mid:
            sum += SegmentTree.query(start, mid, node.left, left, right)
        if right > mid:
            # 此处不同题目中有不同的更新方式
            sum = max(sum, SegmentTree.query(mid + 1, end, node.right, left, right))
        return sum

    @staticmethod
    def update(start: int, end: int, node: Node, left: int, right: int, val: int) -> None:
        # [s, t] 为当前节点包含的区间, 当前根为 node
        # 更新 [left, right] 区间的结果, 区间加上值 val

        # 当前区间为修改区间的子集时直接修改当前节点的值, 然后打标记, 结束修改
        if left <= start and right >= end:
            node.val = val
            node.lazy = val
            return
        SegmentTree.pushdown(node)
        mid = start + ((end - start) >> 1)
        if left <= mid:
            SegmentTree.update(start, mid, node.left, left, right, val)
        if right > mid:
            SegmentTree.update(mid + 1, end, node.right, left, right, val)
        SegmentTree.pushup(node)

    @staticmethod
    def pushup(node: Node):
        # 此处不同题目中有不同的更新方式
        node.val = max(node.left.val, node.right.val)

    @staticmethod
    def pushdown(node: Node):
        if node.left is None:
            node.left = SegmentTree.Node()
        if node.right is None:
            node.right = SegmentTree.Node()
        if node.lazy:
            # 更新当前节点两个子节点的值
            node.left.val = node.lazy
            node.right.val = node.lazy
            # 将标记下传给子节点
            node.left.lazy = node.lazy
            node.right.lazy = node.lazy
            # 清空当前节点的标记
            node.lazy = 0
