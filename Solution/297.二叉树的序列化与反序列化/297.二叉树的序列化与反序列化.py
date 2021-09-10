'''
Descroption: LeetCode 297. �����������л��뷴���л�
Author: EmoryHuang
Date: 2021-06-30 19:16:00
����˼·:
���ò����������
�� # ��ǿ�
'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return
        encode = ''
        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            if node:
                encode += str(node.val)+','
                q.append(node.left)
                q.append(node.right)
            else:
                # ���Ϊ��
                encode += '#,'
        return encode

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return
        vals = data.split(',')
        q = deque()
        root = TreeNode(int(vals[0]))
        q.append(root)
        ind = 1  # ��¼����ڵ�
        while q:
            node = q.popleft()
            if vals[ind] != '#':
                node.left = TreeNode(int(vals[ind]))
                q.append(node.left)
            ind += 1
            if vals[ind] != '#':
                node.right = TreeNode(int(vals[ind]))
                q.append(node.right)
            ind += 1
        return root


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
