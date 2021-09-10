/*
 * @Descroption: LeetCode 208. 实现 Trie (前缀树)
 * @Author: EmoryHuang
 * @Date: 2021-04-14 18:26:36
 * @解题思路:
 * Trie，又称前缀树或字典树，是一棵有根树，其每个节点包含以下字段：
 * 指向子节点的指针数组 children。对于本题而言，数组长度为 26，即小写英文字母的数量。
 * 此时 children[0] 对应小写字母 a，children[1] 对应小写字母 b，…，children[25] 对应小写字母 z。
 * 布尔字段 isEnd，表示该节点是否为字符串的结尾
 */

class Trie {
   public:
    /** Initialize your data structure here. */
    bool isEnd;
    Trie* next[26];
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (node->next[c] == nullptr) node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            node = node->next[c - 'a'];
            if (node == nullptr) return false;
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            node = node->next[c - 'a'];
            if (node == nullptr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */