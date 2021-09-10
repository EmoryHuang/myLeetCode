'''
Descroption: ��ָ Offer II 083. û���ظ�Ԫ�ؼ��ϵ�ȫ����
Author: EmoryHuang
Date: 2021-08-06 16:42:39
Method:
�򵥻���
����û���ظ�Ԫ�أ���˿���ֱ���ж�Ԫ���Ƿ���������
��ȻҲ����ʹ�ö���ռ��¼Ԫ���Ƿ�ʹ��
'''


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans, path, vis = [], [], [False] * len(nums)

        def dfs():
            if len(path) == len(nums):
                ans.append(path[:])
                return
            for i, num in enumerate(nums):
                if not vis[i]:
                    vis[i] = True
                    path.append(num)
                    dfs()
                    vis[i] = False
                    path.pop()

        dfs()
        return ans
