'''
Descroption: LeetCode 715. Range ģ��
Author: EmoryHuang
Date: 2022-06-20 08:46:10
Method:
�߶�����̬����
'''


class SegmentTree:
    class Node:
        def __init__(self):
            self.left = None
            self.right = None
            self.val = False
            self.lazy = False

    def __init__(self) -> None:
        self.root = self.Node()

    @staticmethod
    def query(start: int, end: int, node: Node, left: int, right: int) -> int:
        # [s, t] Ϊ��ǰ�ڵ����������, ��ǰ��Ϊ node
        # ��ѯ [left, right] ����Ľ��

        # ��ǰ����Ϊѯ��������Ӽ�ʱֱ�ӷ��ص�ǰ����ĺ�
        if left <= start and right >= end:
            return node.val
        mid, sum = start + ((end - start) >> 1), True
        SegmentTree.pushdown(node)
        if left <= mid:
            sum = sum and SegmentTree.query(start, mid, node.left, left, right)
        if right > mid:
            sum = sum and SegmentTree.query(mid + 1, end, node.right, left, right)
        return sum

    @staticmethod
    def update(start: int, end: int, node: Node, left: int, right: int, val: int) -> None:
        # [s, t] Ϊ��ǰ�ڵ����������, ��ǰ��Ϊ node
        # ���� [left, right] ����ֵΪ val

        # ��ǰ����Ϊ�޸�������Ӽ�ʱֱ���޸ĵ�ǰ�ڵ��ֵ, Ȼ�����, �����޸�
        if left <= start and right >= end:
            node.val = val
            node.lazy = True
            return
        mid = start + ((end - start) >> 1)
        SegmentTree.pushdown(node)
        if left <= mid:
            SegmentTree.update(start, mid, node.left, left, right, val)
        if right > mid:
            SegmentTree.update(mid + 1, end, node.right, left, right, val)
        SegmentTree.pushup(node)

    @staticmethod
    def pushup(node: Node):
        node.val = node.left.val and node.right.val

    @staticmethod
    def pushdown(node: Node):
        if node.left is None:
            node.left = SegmentTree.Node()
        if node.right is None:
            node.right = SegmentTree.Node()
        if node.lazy:
            # ���µ�ǰ�ڵ������ӽڵ��ֵ
            node.left.val = node.val
            node.right.val = node.val
            # ������´����ӽڵ�
            node.left.lazy = True
            node.right.lazy = True
            # ��յ�ǰ�ڵ�ı��
            node.lazy = False


class RangeModule:
    def __init__(self):
        self.tree = SegmentTree()

    def addRange(self, left: int, right: int) -> None:
        self.tree.update(1, int(1e9), self.tree.root, left, right - 1, True)

    def queryRange(self, left: int, right: int) -> bool:
        return self.tree.query(1, int(1e9), self.tree.root, left, right - 1)

    def removeRange(self, left: int, right: int) -> None:
        self.tree.update(1, int(1e9), self.tree.root, left, right - 1, False)


# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)