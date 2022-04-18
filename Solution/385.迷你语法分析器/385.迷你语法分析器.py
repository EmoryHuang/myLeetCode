'''
Descroption: LeetCode 385. �����﷨������
Author: EmoryHuang
Date: 2022-04-15 09:03:17
Method:
dfs
ʹ�� deep ��¼��ǰ����λ�õ���ȣ�ÿ�����������ţ���ȼ� 1�����������ţ���ȼ� 1
start ��¼��ʼλ�ã��� start ����ǰλ��֮����ַ���ȡ�����ݹ���ú���
'''

# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """


class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        # ���Ϊ����ֱ�ӷ���
        if not s:
            return NestedInteger()
        # ���ֻ��һ��
        if s[0] != '[':
            return NestedInteger(int(s))
        # ���Ϊ [] �򷵻ؿ�
        if len(s) <= 2:
            return NestedInteger()
        ans = NestedInteger()
        # deep ��¼���
        deep, start = 0, 1
        for i in range(1, len(s)):
            if deep == 0 and (s[i] == ',' or i == len(s) - 1):
                ans.add(self.deserialize(s[start:i]))
                start = i + 1
            elif s[i] == '[':
                deep += 1
            elif s[i] == ']':
                deep -= 1
        return ans