'''
Descroption: LeetCode 677. ��ֵӳ��
Author: EmoryHuang
Date: 2021-11-14 14:17:50
Method:
��ϣ���¼�����ַ���
���ʱ������ϣ��, ʹ������ƥ��
'''


class MapSum:
    def __init__(self):
        self.hash = defaultdict(int)

    def insert(self, key: str, val: int) -> None:
        self.hash[key] = val

    def sum(self, prefix: str) -> int:
        ans = 0
        for key, val in self.hash.items():
            if re.match(prefix, key):
                ans += val
        return ans


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)