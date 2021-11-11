'''
Descroption: 剑指 Offer 33. 二叉搜索树的后序遍历序列
Author: EmoryHuang
Date: 2021-11-11 19:54:07
Method:
单调栈
维护一个大根堆，只要栈顶元素还比当前节点大，就表示还是右子树，要移除
直到栈顶元素小于节点，或者栈为空
左子树的每个节点，都要比子树的根要小
'''


class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        pre = float('inf')
        heap = []
        # 倒序遍历
        for i in range(len(postorder) - 1, -1, -1):
            # 左子树元素较小
            if postorder[i] > pre:
                return False
            # 维护一个大根堆
            # 只要栈顶元素还比当前节点大，就表示还是右子树，要移除
            # 栈顶的上一个元素就是子树节点的根
            while heap and postorder[i] < -heap[0]:
                pre = -heapq.heappop(heap)
            heapq.heappush(heap, -postorder[i])
        return True
