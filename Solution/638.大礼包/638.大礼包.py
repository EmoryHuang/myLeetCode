'''
Descroption: LeetCode 638. �����
Author: EmoryHuang
Date: 2021-10-24 18:52:44
Method:
dfs ���仯
ʹ�� cache ��¼���ֵ�������
���ȿ����ڵ�ǰ�����²����������Ļ��ѣ�Ȼ�����ÿ����������ж��Ƿ��������
���ڷ���Ҫ��Ĵ��������������
Ȼ��ݹ����ⲻͬ�����µ���С����
'''


class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]],
                       needs: List[int]) -> int:
        @lru_cache(None)
        def dfs(cur) -> int:
            ans = 0
            # ����������
            for i in range(len(cur)):
                ans += cur[i] * price[i]
            # ����ÿ�����
            for bag in special:
                nxt = tuple(x - y for x, y in zip(cur, bag))
                if all(x >= 0 for x in nxt):
                    ans = min(ans, dfs(nxt) + bag[-1])
            return ans

        return dfs(tuple(needs))