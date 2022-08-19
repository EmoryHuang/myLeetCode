'''
Descroption: LeetCode 1418. 点菜展示表
Author: EmoryHuang
Date: 2021-07-06 20:25:58
解题思路:
使用哈希表统计 桌号 : {餐品 : 个数}
然后统计输出
'''


class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        ans = []
        foods = set()
        # 桌号 : {餐品 : 个数}
        hash = defaultdict(lambda: defaultdict(int))
        for _, table, food in orders:
            foods.add(food)
            hash[int(table)][food] += 1
        foods = sorted(foods)
        ans.append(['Table'] + foods)
        for table in sorted(hash.keys()):
            cur = []
            cur.append(str(table))
            for food in foods:
                cur.append(str(hash[table][food]))
            ans.append(cur)
        return ans
