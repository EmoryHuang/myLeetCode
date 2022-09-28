/*
 * @Descroption: LeetCode 433. 最小基因变化
 * @Author: EmoryHuang
 * @Date: 2022-05-07 09:01:35
 * @Method:
 * bfs
 * 使用队列记录当前状态，以及步数
 * bfs 枚举所有可能的状态
 */

class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> bank_set(bank.begin(), bank.end());
        if (bank_set.find(end) == bank_set.end()) return -1;
        // 记录每个字符可变换的字符
        unordered_map<char, string> change{{'A', "CGT"}, {'C', "AGT"}, {'G', "ACT"}, {'T', "ACG"}};
        // 队列记录状态和步数
        queue<pair<string, int>> q;
        q.push({start, 0});
        // bfs
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur.first == end) return cur.second;
            // 枚举可变换的字符串
            for (int i = 0; i < cur.first.size(); ++i) {
                for (int j = 0; j < 4; ++j) {
                    string next = cur.first;
                    next[i] = change[cur.first[i]][j];
                    if (bank_set.find(next) != bank_set.end()) {
                        q.push({next, cur.second + 1});
                        bank_set.erase(next);
                    }
                }
            }
        }
        return -1;
    }
};