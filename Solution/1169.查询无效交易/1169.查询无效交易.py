'''
Descroption: LeetCode 1169. 查询无效交易
Author: EmoryHuang
Date: 2021-09-10 15:56:48
Method:
暴力
对于每条交易记录，判断其金额是否大于1000
查找是否存在在另一个城市中同名的另一笔交易，并且相隔不超过 60 分钟
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