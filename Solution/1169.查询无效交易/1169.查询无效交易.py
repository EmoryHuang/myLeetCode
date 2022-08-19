'''
Descroption: LeetCode 1169. ��ѯ��Ч����
Author: EmoryHuang
Date: 2021-09-10 15:56:48
Method:
����
����ÿ�����׼�¼���ж������Ƿ����1000
�����Ƿ��������һ��������ͬ������һ�ʽ��ף�������������� 60 ����
'''


class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        ls = [i.split(',') for i in transactions]
        ans = []
        for i, u in enumerate(ls):
            if int(u[2]) > 1000:
                ans.append(','.join(u))
                continue
            for j, v in enumerate(ls):
                if i == j: continue
                if u[0] == v[0] and u[3] != v[3] and abs(int(u[1]) - int(v[1])) <= 60:
                    ans.append(','.join(u))
                    break
        return ans