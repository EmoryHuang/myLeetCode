'''
Descroption: LeetCode 676. ʵ��һ��ħ���ֵ�
Author: EmoryHuang
Date: 2021-08-11 19:51:07
Method:
���������������ʴ����ϣ���У��ж�����������ֵ��еĵ����Ƿ�ֻ��һ����ĸ
'''


class MagicDictionary:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.mp = defaultdict(list)

    def buildDict(self, dictionary: List[str]) -> None:
        for word in dictionary:
            self.mp[len(word)].append(word)

    def search(self, searchWord: str) -> bool:
        n = len(searchWord)
        for word in self.mp[n]:
            cnt = 0
            for i, c in enumerate(word):
                if searchWord[i] != c:
                    cnt += 1
            if cnt == 1:
                return True
        return False


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)