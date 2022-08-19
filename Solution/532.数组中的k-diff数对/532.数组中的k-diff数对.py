'''
Descroption: LeetCode 532. �����е� k-diff ����
Author: EmoryHuang
Date: 2022-06-16 09:01:58
Method:
ʹ�ù�ϣ���¼���ֵ�����
���ڵ�ǰ���� num����� num - k �� num + k �ڹ�ϣ���У���Ϊ k-diff ����
'''


class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        vis, ans = set(), set()
        for num in nums:
            if num - k in vis:
                ans.add(num - k)
            if num + k in vis:
                ans.add(num)
            vis.add(num)
        return len(ans)
