'''
Descroption: LeetCode 1980. �ҳ���ͬ�Ķ������ַ���
Author: EmoryHuang
Date: 2021-11-06 16:13:30
Method:
����
dfs �����ַ��������ҵ���һ����ͬ�Ķ������ַ�����������ѭ��
'''


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        def dfs(cur: str):
            if not self.flag:
                if len(cur) == len(nums):
                    if cur not in nums:
                        self.ans = cur
                        self.flag = True
                    return
                for c in ['0', '1']:
                    dfs(cur + c)

        self.ans = ''
        self.flag = False
        dfs('')
        return self.ans
