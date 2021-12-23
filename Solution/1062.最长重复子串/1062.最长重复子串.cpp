/*
 * @Descroption: LeetCode 1044. 最长重复子串
 * @Author: EmoryHuang
 * @Date: 2021-12-23 14:42:20
 * @Method:
 * 二分 + 字符串哈希
 * 使用二分查找最长重复子串的长度，滚动哈希查找重复出现的子串
 * */
 
class Solution {
   public:
    vector<unsigned long long> h, p;
    string check(string s, int len) {
        int n = s.size();
        unordered_set<unsigned long long> st;
        // 滚动哈希查找重复出现的子串
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            // 询问子串哈希
            unsigned long long cur = h[j] - h[i - 1] * p[j - i + 1];
            if (st.count(cur)) return s.substr(i - 1, len);
            st.insert(cur);
        }
        return "";
    }
    string longestDupSubstring(string s) {
        int B = 233;
        int n = s.size();
        h.resize(n + 1);
        p.resize(n + 1);
        p[0] = 1;
        // h[i] 表示 f(s[1...i]), 即原串长度为 i 的前缀的哈希值
        // p[i] 为次方数组
        for (int i = 0; i < n; i++) {
            h[i + 1] = h[i] * B + s[i];
            p[i + 1] = p[i] * B;
        }
        string ans;
        int l = 0, r = n;
        while (l < r) {
            // mid 为最长重复子串的长度
            int mid = l + r + 1 >> 1;
            string t = check(s, mid);
            if (t.size() != 0) {
                l = mid;
            } else {
                r = mid - 1;
            }
            ans = t.size() > ans.size() ? t : ans;
        }
        return ans;
    }
};