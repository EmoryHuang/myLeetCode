'''
Descroption: LeetCode 961. �ظ� N �ε�Ԫ��
Author: EmoryHuang
Date: 2021-06-28 14:27:00
����˼·:
���⣬��ϣ�����
'''


class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        hash = defaultdict(int)
        for num in nums:
            hash[num] += 1
            if hash[num] > 1:  # �� 2 ����Ϊ������
                return num
