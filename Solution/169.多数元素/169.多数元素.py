'''
Descroption: LeetCode 169. ����Ԫ��
Author: EmoryHuang
Date: 2021-07-11 14:33:18
����˼·:
����һ����ϣ��
ʹ��һ����ϣ���¼Ԫ�ص�����
��������Ħ��ͶƱ
Ħ��ͶƱ��ÿ�ν�������ͬ��Ԫ�ؽ��С�����������������Ԫ��ʣ�࣬�򡸿��ܡ�ΪԪ�ظ�����������һ����Ǹ�
֮���ٽ���һ�α����������������ܡ�����ҪԪ�� x �ĳ��ִ����Ƿ񳬹�����һ��
'''


class Solution:
    # ����һ����ϣ��
    # def majorityElement(self, nums: List[int]) -> int:
    #     hash = defaultdict(int)
    #     for num in nums:
    #         hash[num] += 1
    #         if hash[num] >= len(nums) // 2:
    #             return num
    #     return 0

    # ��������Ħ��ͶƱ
    def majorityElement(self, nums: List[int]) -> int:
        ans = cnt = 0
        for i, num in enumerate(nums):
            if cnt == 0:
                ans = num
            if ans == num:
                cnt += 1
            else:
                cnt -= 1
        cnt = 0
        for num in nums:
            if ans == num:
                cnt += 1
        return ans if cnt > len(nums) // 2 else 0