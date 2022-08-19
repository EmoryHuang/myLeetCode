'''
Descroption: LeetCode 211. ������������� - ���ݽṹ���
Author: EmoryHuang
Date: 2021-10-19 09:20:05
Method:
�ֵ�����ǰ׺����
��������ӵ��ֵ����У��Ӹ��ڵ㿪ʼ����
�����ǰ�ַ�����ĸ�����жϵ�ǰ�ַ���Ӧ���ӽ���Ƿ���ڣ�����������һ���ַ�
�����ǰ�ַ��ǵ�ţ���Ҫ�Ե�ǰ�������зǿ��ӽ�����������һ���ַ�
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
                # �����ǰ�ַ�����ĸ�����жϵ�ǰ�ַ���Ӧ���ӽ���Ƿ���ڣ�����������һ���ַ�
                child = node.children[ord(c) - ord('a')]
                if child and dfs(child, idx + 1):
                    return True
            else:
                # �����ǰ�ַ��ǵ�ţ���Ҫ�Ե�ǰ�������зǿ��ӽ�����������һ���ַ�
                for child in node.children:
                    if child and dfs(child, idx + 1):
                        return True
            return False

        return dfs(self.trie, 0)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
