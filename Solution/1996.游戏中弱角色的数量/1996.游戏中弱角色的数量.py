'''
Descroption: LeetCode 1996. 游戏中弱角色的数量
Author: EmoryHuang
Date: 2021-09-17 11:04:58
Method:
排序 + 单调栈
按攻击力递减，防御力递增排序
从前往后遍历，记录当前最大防御力
若当前防御力小于最大防御力，那么前面一定有一个人物的攻击力大于当前攻击力
'''


class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        n = len(properties)
        # 按攻击力递减，防御力递增排序
        properties.sort(key=lambda x: (-x[0], x[1]))
        # 记录当前最大防御力
        ans, maxdfs = 0, -1
        for i in range(n):
            # 由于攻击力递减排序
            # 因此若当前防御力小于最大防御力
            # 那么前面一定有一个人物的攻击力大于当前攻击力
            # 攻击力不可能相同，因为防御力递增排序
            if maxdfs > properties[i][1]:
                ans += 1
            maxdfs = max(maxdfs, properties[i][1])
        return ans
