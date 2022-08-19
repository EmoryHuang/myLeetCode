'''
Descroption: ��ָ Offer II 084. �����ظ�Ԫ�ؼ��ϵ�ȫ���� 
Author: EmoryHuang
Date: 2021-08-06 16:59:23
Method:
�򵥻���
�������ظ�Ԫ�أ���˿�����û���ظ�Ԫ�صĻ����ϣ��жϵ�ǰԪ���Ƿ�Ϊ�ظ�Ԫ�ؼ���
'''


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans, path, vis = [], [], [False] * len(nums)

        def dfs():
            if len(path) == len(nums):
                ans.append(path[:])
                return
            for i, num in enumerate(nums):
                if not vis[i]:
                    if i > 0 and nums[i] == nums[i - 1] and vis[i - 1]:
                        continue
                    vis[i] = True
                    path.append(num)
                    dfs()
                    vis[i] = False
                    path.pop()

        nums.sort()
        dfs()
        return ans
