'''
Descroption: LeetCode 211. 添加与搜索单词 - 数据结构设计
Author: EmoryHuang
Date: 2021-10-19 09:20:05
Method:
字典树（前缀树）
将单词添加到字典树中，从根节点开始搜索
如果当前字符是字母，则判断当前字符对应的子结点是否存在，继续搜索下一个字符
如果当前字符是点号，需要对当前结点的所有非空子结点继续搜索下一个字符
'''


class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.end = False

    def insert(self, word: str):
        node = self
        for c in word:
            c = ord(c) - ord('a')
            if not node.children[c]:
                node.children[c] = Trie()
            node = node.children[c]
        node.end = True


class WordDictionary:
    def __init__(self):
        self.trie = Trie()

    def addWord(self, word: str) -> None:
        self.trie.insert(word)

    def search(self, word: str) -> bool:
        def dfs(node: Trie, idx: int) -> bool:
            if idx == len(word):
                return node.end
            c = word[idx]
            if c != '.':
                # 如果当前字符是字母，则判断当前字符对应的子结点是否存在，继续搜索下一个字符
                child = node.children[ord(c) - ord('a')]
                if child and dfs(child, idx + 1):
                    return True
            else:
                # 如果当前字符是点号，需要对当前结点的所有非空子结点继续搜索下一个字符
                for child in node.children:
                    if child and dfs(child, idx + 1):
                        return True
            return False

        return dfs(self.trie, 0)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
