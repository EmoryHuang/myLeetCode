'''
Descroption: LeetCode 676. 实现一个魔法字典
Author: EmoryHuang
Date: 2021-08-11 19:51:07
Method:
暴力遍历，将单词存入哈希表中，判断这个单词与字典中的单词是否只差一个字母
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