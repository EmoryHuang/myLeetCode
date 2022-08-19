/*
 * @Descroption: LeetCode 1807. 替换字符串中的括号内容
 * @Author: EmoryHuang
 * @Date: 2021-09-24 19:07:52
 * @Method:
 * 哈希表
 * 遍历字符串，若遇到括号则读取 key 并获取对应的 value
 * 若 key 不存在则填 ?
 */

class Solution {
   public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> hash;
        for (auto p : knowledge) hash[p[0]] = p[1];
        string ans;
        int i = 0;
        while (i < s.size()) {
            string key;
            if (s[i] == '(') {
                i++;
                while (s[i] != ')') key += s[i++];
                // 若不存在键值
                if (hash.count(key) == 0)
                    ans += '?';
                else
                    ans += hash[key];
            } else if (s[i] != ')')
                ans += s[i];
            i++;
        }
        return ans;
    }
};