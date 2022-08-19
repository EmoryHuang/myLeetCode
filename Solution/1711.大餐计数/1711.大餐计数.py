'''
Descroption: LeetCode 1711. ��ͼ���
Author: EmoryHuang
Date: 2021-07-07 19:14:19
����˼·:
�ù�ϣ���¼�����Լ������ֵĴ���
�������п��ܵ�2���ݣ����ñ�����2���ݼ�ȥ��ǰ�����ó���Ӧ����
'''


class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        ans = 0
        hash = defaultdict(int)
        for num in deliciousness:
            for i in range(22):
                if (1 << i) - num in hash:
                    cnt = hash[(1 << i) - num]
                    ans += cnt
                    ans %= 1000000007
            hash[num] += 1
        return ans
