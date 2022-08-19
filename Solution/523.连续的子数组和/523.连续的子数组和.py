'''
Descroption: LeetCode 523. �������������
Author: EmoryHuang
Date: 2021-06-02 10:14:00
����˼·:
Ԥ����ǰ׺������ pre��Ȼ��ٶ� [i, j] �����ǵ�Ŀ�����䣬��ô�У�
sum[j] - sum[i - 1] = n * k
Ҫʹ�����߳� k ���Ϊ��������Ҫ���� sum[j] �� sum[i - 1] �� k ȡ����ͬ
ʹ�ù�ϣ������ֹ�������
�����ǰ�����ڹ�ϣ�����Ѿ����ڣ������������С����Ϊ 2�������
�����ǰ�����ڹ�ϣ���в����ڣ��򽫵�ǰ�����͵�ǰ�±� i �ļ�ֵ�Դ����ϣ����
'''


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        if k == 0:
            return False
        hash = {}
        pre = 0
        hash[0] = -1
        for i in range(len(nums)):
            pre = (pre + nums[i]) % k  # ǰ׺�͵�����
            # ����ͬ��ǰ׺�ͣ������������С����Ϊ 2
            if pre in hash and i - hash[pre] > 1:
                return True
            elif pre not in hash:
                hash[pre] = i  # ��¼��������״γ��ֵ�λ��
        return False
