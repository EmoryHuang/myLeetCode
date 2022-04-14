'''
Descroption: LeetCode 380. O(1) ʱ����롢ɾ���ͻ�ȡ���Ԫ��
Author: EmoryHuang
Date: 2022-04-13 08:48:45
Method:
���� + ��ϣ��
����洢Ԫ�أ���ϣ��洢��Ӧ���±�
ɾ������ʱ���䳤��������һ��Ԫ���ƶ�����ɾ��Ԫ�ص��±괦��Ȼ��ɾ���䳤��������һ��Ԫ�ء�
'''


class RandomizedSet:
    def __init__(self):
        self.nums = []
        self.hash = defaultdict(int)

    def insert(self, val: int) -> bool:
        if val in self.hash:
            return False
        self.hash[val] = len(self.nums)
        self.nums.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.hash:
            return False
        index = self.hash[val]
        self.nums[index] = self.nums[-1]
        self.hash[self.nums[index]] = index
        self.nums.pop()
        del self.hash[val]
        return True

    def getRandom(self) -> int:
        return choice(self.nums)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
