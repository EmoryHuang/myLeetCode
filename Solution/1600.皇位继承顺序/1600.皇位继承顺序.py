'''
Descroption: LeetCode 1600. 皇位继承顺序
Author: EmoryHuang
Date: 2021-06-20 12:18:00
解题思路:
使用多叉树的方式存储亲属关系，
以 kingName 作为根节点，每次添加一条从 parentName 到 childName 的边
使用 set 记录死亡的人
查找时，使用前序遍历的方式查找，
'''


class ThroneInheritance:

    def __init__(self, kingName: str):
        self.king = kingName
        self.dead = set()
        self.edges = defaultdict(list)

    def birth(self, parentName: str, childName: str) -> None:
        self.edges[parentName].append(childName)

    def death(self, name: str) -> None:
        self.dead.add(name)

    def getInheritanceOrder(self) -> List[str]:
        ans = []

        def preorder(name: str) -> None:
            if name not in self.dead:
                ans.append(name)
            if name in self.edges:
                for childname in self.edges[name]:
                    preorder(childname)

        preorder(self.king)
        return ans

# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()
