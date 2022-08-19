/*
 * @Descroption: LeetCode 211. ������������� - ���ݽṹ���
 * @Author: EmoryHuang
 * @Date: 2021-10-19 13:40:20
 * @Method:
 * �ֵ�����ǰ׺����
 * ��������ӵ��ֵ����У��Ӹ��ڵ㿪ʼ����
 * �����ǰ�ַ�����ĸ�����жϵ�ǰ�ַ���Ӧ���ӽ���Ƿ���ڣ�����������һ���ַ�
 * �����ǰ�ַ��ǵ�ţ���Ҫ�Ե�ǰ�������зǿ��ӽ�����������һ���ַ�
 */

struct Trie {
    vector<Trie *> child;
    bool end;
    Trie() {
        this->child = vector<Trie *>(26, nullptr);
        this->end = false;
    }
};

void insert(Trie *root, string word) {
    Trie *node = root;
    for (auto c : word) {
        c = c - 'a';
        if (node->child[c] == nullptr) {
            node->child[c] = new Trie();
        }
        node = node->child[c];
    }
    node->end = true;
}

class WordDictionary {
   public:
    Trie *trie = new Trie();
    WordDictionary() {}

    void addWord(string word) { insert(trie, word); }

    bool dfs(Trie *node, int idx, string word) {
        if (idx == word.size()) return node->end;
        char c = word[idx];
        if (c != '.') {
            auto child = node->child[int(c - 'a')];
            if (child && dfs(child, idx + 1, word)) return true;
        } else {
            for (auto child : node->child)
                if (child && dfs(child, idx + 1, word)) return true;
        }
        return false;
    }

    bool search(string word) { return dfs(trie, 0, word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */