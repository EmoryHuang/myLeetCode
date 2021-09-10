'''
Descroption: ������ 17.10. ��ҪԪ��
Author: EmoryHuang
Date: 2021-07-09 19:20:08
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
    #         if hash[num] > len(nums) // 2:
    #             return num
    #     return -1

    # ��������Ħ��ͶƱ
    def majorityElement(self, nums: List[int]) -> int:
        res, cnt = -1, 0
        for num in nums:
            if cnt == 0:
                res = num
            if num == res:
                cnt += 1
            else:
                cnt -= 1
        return res if cnt and nums.count(res) > len(nums) // 2 else -1
