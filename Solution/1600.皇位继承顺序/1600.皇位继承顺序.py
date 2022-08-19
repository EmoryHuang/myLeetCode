'''
Descroption: LeetCode 1600. ��λ�̳�˳��
Author: EmoryHuang
Date: 2021-06-20 12:18:00
����˼·:
ʹ�ö�����ķ�ʽ�洢������ϵ��
�� kingName ��Ϊ���ڵ㣬ÿ�����һ���� parentName �� childName �ı�
ʹ�� set ��¼��������
����ʱ��ʹ��ǰ������ķ�ʽ���ң�
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
