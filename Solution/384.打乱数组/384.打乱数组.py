'''
Descroption: LeetCode 384. ��������
Author: EmoryHuang
Date: 2021-11-22 18:32:45
Method:
ϴ���㷨
�� [i,n) �������ȡһ���±� j
���� i ��Ԫ����� j ��Ԫ�ؽ���
'''


class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums

    def reset(self) -> List[int]:
        return self.nums

    def shuffle(self) -> List[int]:
        ans = self.nums.copy()
        # �� [i,n) �������ȡһ���±� j
        # ���� i ��Ԫ����� j ��Ԫ�ؽ���
        for i in range(len(ans)):
            j = random.randint(0, i)
            ans[i], ans[j] = ans[j], ans[i]
        return ans

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()