'''
Descroption: LeetCode 699. ����ķ���
Author: EmoryHuang
Date: 2022-05-26 21:01:40
Method:
����һ������ö��
ö��ÿһ�������Լ��������֮ǰ�ķ��飬����Ƿ����ص�
�����ص��ĸ������߶�

���������߶���
O(log(n))
'''


class Solution:
    # ����һ������ö��
    # def fallingSquares(self, positions: List[List[int]]) -> List[int]:
    #     n = len(positions)
    #     height = [0] * n
    #     # ö��ÿһ������
    #     for i, (left, side) in enumerate(positions):
    #         right = left + side - 1
    #         height[i] = side
    #         # ö���������֮ǰ�ķ��飬����Ƿ����ص�
    #         for j in range(i):
    #             left_pre = positions[j][0]
    #             right_pre = positions[j][0] + positions[j][1] - 1
    #             if left <= right_pre and left_pre <= right:
    #                 height[i] = max(height[i], height[j] + side)
    #     # �������߶�
    #     for i in range(1, n):
    #         height[i] = max(height[i], height[i - 1])
    #     return height

    # ���������߶���
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
        # [s, t] Ϊ��ǰ�ڵ����������, ��ǰ��Ϊ node
        # ��ѯ [left, right] ����Ľ��

        # ��ǰ����Ϊѯ��������Ӽ�ʱֱ�ӷ��ص�ǰ����ĺ�
        if left <= start and right >= end:
            return node.val
        SegmentTree.pushdown(node)
        mid, sum = start + ((end - start) >> 1), 0
        if left <= mid:
            sum += SegmentTree.query(start, mid, node.left, left, right)
        if right > mid:
            # �˴���ͬ��Ŀ���в�ͬ�ĸ��·�ʽ
            sum = max(sum, SegmentTree.query(mid + 1, end, node.right, left, right))
        return sum

    @staticmethod
    def update(start: int, end: int, node: Node, left: int, right: int, val: int) -> None:
        # [s, t] Ϊ��ǰ�ڵ����������, ��ǰ��Ϊ node
        # ���� [left, right] ����Ľ��, �������ֵ val

        # ��ǰ����Ϊ�޸�������Ӽ�ʱֱ���޸ĵ�ǰ�ڵ��ֵ, Ȼ�����, �����޸�
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
        # �˴���ͬ��Ŀ���в�ͬ�ĸ��·�ʽ
        node.val = max(node.left.val, node.right.val)

    @staticmethod
    def pushdown(node: Node):
        if node.left is None:
            node.left = SegmentTree.Node()
        if node.right is None:
            node.right = SegmentTree.Node()
        if node.lazy:
            # ���µ�ǰ�ڵ������ӽڵ��ֵ
            node.left.val = node.lazy
            node.right.val = node.lazy
            # ������´����ӽڵ�
            node.left.lazy = node.lazy
            node.right.lazy = node.lazy
            # ��յ�ǰ�ڵ�ı��
            node.lazy = 0
