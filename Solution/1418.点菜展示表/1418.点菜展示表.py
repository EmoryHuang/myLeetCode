'''
Descroption: LeetCode 1418. ���չʾ��
Author: EmoryHuang
Date: 2021-07-06 20:25:58
����˼·:
ʹ�ù�ϣ��ͳ�� ���� : {��Ʒ : ����}
Ȼ��ͳ�����
'''


class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        ans = []
        foods = set()
        # ���� : {��Ʒ : ����}
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
