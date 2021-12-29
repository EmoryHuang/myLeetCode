/*
 * @Descroption: LeetCode 472. ���Ӵ�
 * @Author: EmoryHuang
 * @Date: 2021-12-28 12:31:38
 * @Method:
 * ����һ: �ֵ���
 * ����ÿ���ǿյ��ʣ��жϸõ����ǲ������Ӵʣ�
 * ��������Ӵ��򽫸õ��ʼ��������飬����������Ӵ��򽫸õ��ʼ����ֵ���
 *
 * �жϵ����ǲ������Ӵ�:
 *     �ӵ��ʵĵ�һ���ַ���ʼ�����ֵ�������������ÿ���ַ���Ӧ�Ľ��
 *         1. ���һ���ַ���Ӧ�Ľ�����ֵ����в����ڣ���ǰ���������ʧ�ܣ��ص���һ�����ʵĽ�β��������
 *         2. ���һ���ַ���Ӧ�Ľ���ǵ��ʵĽ�β�����ҵ���һ�����̵ĵ��ʣ��Ӹ��ַ��ĺ�һ���ַ���ʼ������һ�����̵ĵ���
 *
 * ������: ��̬�滮 + �ַ�����ϣ
 * �жϵ����ǲ������Ӵ�:
 *     dp[i]��ʾ word[:i] �ܹ��зֳ������ item ���ĸ���
 *     �� dp[i] ������ö�ٷ�Χ [i + 1, n]���ҵ����� dp[i] ���ܸ��µ�״̬ dp[j]��������ʹ�� dp[i] ������ dp[j]
 *     ״̬ת�Ʒ���: dp[j] = max(dp[j], dp[i] + 1)
 *
 * ͨ�����ַ�����ϣ����ʽ���Ż��ж�ĳ���Ӵ��Ƿ������ words ��
 * Ԥ����ÿ�� words[i] �Ĺ�ϣֵ�������� HashSet ��, ֮���ж�ĳ�����Ƿ������ HashSet ��
 * */

struct Trie {
    bool is_end;
    vector<Trie*> children;
    Trie() {
        this->children = vector<Trie*>(26, nullptr);
        this->is_end = false;
    }
};

class Solution {
   public:
    // ����һ���ֵ���
    Trie* trie = new Trie();

    void insert(string word) {
        Trie* node = trie;
        for (auto w : word) {
            int idx = w - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->is_end = true;
    }
    bool dfs(string word, int start) {
        if (start == word.size()) return true;
        Trie* node = trie;
        for (int i = start; i < word.size(); i++) {
            node = node->children[word[i] - 'a'];
            // ���ĳ���ַ���Ӧ�Ľ�㲻����
            if (!node) return false;
            // ����ҵ��˽�β�����Ӹ��ַ��ĺ�һ���ַ���ʼ������һ�����̵ĵ���
            if (node->is_end && dfs(word, i + 1)) return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b) { return a.size() < b.size(); });
        int n = words.size();
        vector<string> ans;
        for (auto word : words) {
            if (word.size() == 0) continue;
            if (dfs(word, 0))
                ans.push_back(word);
            else
                insert(word);
        }
        return ans;
    }

    // ����������̬�滮 + �ַ�����ϣ
    // int B = 131, OFFSET = 128;
    // unordered_set<unsigned long long> st;
    // bool check(string word) {
    //     int n = word.size();
    //     // dp[i]��ʾ word[:i] �ܹ��зֳ������ item ���ĸ���
    //     vector<int> dp(n + 1, -1);
    //     dp[0] = 0;
    //     // ö��ÿ���Ӵ�
    //     for (int i = 0; i <= n; i++) {
    //         if (dp[i] == -1) continue;
    //         unsigned long long cur = 0;
    //         // ������ word[i] ��ͷ��ÿ���Ӵ�
    //         // ���Ӵ����б��У������ dp[j] = max(dp[j], dp[i] + 1)
    //         for (int j = i + 1; j <= n; j++) {
    //             cur = cur * B + word[j - 1] - 'a' + OFFSET;
    //             // ����ϣֵ��ͬ
    //             if (st.count(cur)) dp[j] = max(dp[j], dp[i] + 1);
    //         }
    //         if (dp[n] > 1) return true;
    //     }
    //     return false;
    // }
    // vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    //     int n = words.size();
    //     vector<string> ans;
    //     // �ַ�����ϣ�ж�ĳ���Ӵ��Ƿ������ words ��
    //     for (auto word : words) {
    //         unsigned long long h = 0;
    //         // �ַ�����ϣ��ͻͨ������ offset ���
    //         for (auto c : word) h = h * B + c - 'a' + OFFSET;
    //         st.insert(h);
    //     }
    //     for (auto word : words)
    //         if (check(word)) ans.push_back(word);
    //     return ans;
    // }
};