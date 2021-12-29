/*
 * @Descroption: LeetCode 472. 连接词
 * @Author: EmoryHuang
 * @Date: 2021-12-28 12:31:38
 * @Method:
 * 方法一: 字典树
 * 对于每个非空单词，判断该单词是不是连接词，
 * 如果是连接词则将该单词加入结果数组，如果不是连接词则将该单词加入字典树
 *
 * 判断单词是不是连接词:
 *     从单词的第一个字符开始，在字典树中依次搜索每个字符对应的结点
 *         1. 如果一个字符对应的结点在字典树中不存在，则当前的搜索结果失败，回到上一个单词的结尾继续搜索
 *         2. 如果一个字符对应的结点是单词的结尾，则找到了一个更短的单词，从该字符的后一个字符开始搜索下一个更短的单词
 *
 * 方法二: 动态规划 + 字符串哈希
 * 判断单词是不是连接词:
 *     dp[i]表示 word[:i] 能够切分出的最大 item 数的个数
 *     从 dp[i] 出发，枚举范围 [i + 1, n]，找到可由 dp[i] 所能更新的状态 dp[j]，并尝试使用 dp[i] 来更新 dp[j]
 *     状态转移方程: dp[j] = max(dp[j], dp[i] + 1)
 *
 * 通过「字符串哈希」方式来优化判断某个子串是否存在于 words 中
 * 预处理每个 words[i] 的哈希值，并存入 HashSet 中, 之后判断某个数是否存在于 HashSet 中
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
    // 方法一：字典树
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
            // 如果某个字符对应的结点不存在
            if (!node) return false;
            // 如果找到了结尾符，从该字符的后一个字符开始搜索下一个更短的单词
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

    // 方法二：动态规划 + 字符串哈希
    // int B = 131, OFFSET = 128;
    // unordered_set<unsigned long long> st;
    // bool check(string word) {
    //     int n = word.size();
    //     // dp[i]表示 word[:i] 能够切分出的最大 item 数的个数
    //     vector<int> dp(n + 1, -1);
    //     dp[0] = 0;
    //     // 枚举每个子串
    //     for (int i = 0; i <= n; i++) {
    //         if (dp[i] == -1) continue;
    //         unsigned long long cur = 0;
    //         // 遍历以 word[i] 开头的每个子串
    //         // 若子串在列表中，则更新 dp[j] = max(dp[j], dp[i] + 1)
    //         for (int j = i + 1; j <= n; j++) {
    //             cur = cur * B + word[j - 1] - 'a' + OFFSET;
    //             // 若哈希值相同
    //             if (st.count(cur)) dp[j] = max(dp[j], dp[i] + 1);
    //         }
    //         if (dp[n] > 1) return true;
    //     }
    //     return false;
    // }
    // vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    //     int n = words.size();
    //     vector<string> ans;
    //     // 字符串哈希判断某个子串是否存在于 words 中
    //     for (auto word : words) {
    //         unsigned long long h = 0;
    //         // 字符串哈希冲突通过增加 offset 解决
    //         for (auto c : word) h = h * B + c - 'a' + OFFSET;
    //         st.insert(h);
    //     }
    //     for (auto word : words)
    //         if (check(word)) ans.push_back(word);
    //     return ans;
    // }
};