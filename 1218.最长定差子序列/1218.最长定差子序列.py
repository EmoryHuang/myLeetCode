'''
Descroption: LeetCode 1218. �����������
Author: EmoryHuang
Date: 2021-08-10 13:44:54
Method:
��̬�滮 + ��ϣ��
ʹ�ù�ϣ������nums[i]��β�ĵȲ����е�����
�� num - difference ���ڹ�ϣ���У�����Ϊ 1
������Ϊ hash[num - difference] + 1
'''


class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        # ʹ�ù�ϣ������nums[i]��β�ĵȲ����е�����
        hash = defaultdict(int)
        for num in arr:
            # �� num - difference ���ڹ�ϣ���У�����Ϊ 1
            hash[num] = hash[num - difference] + 1
        return max(hash.values())