/*
 * @Descroption: LeetCode 1044. ��ظ��Ӵ�
 * @Author: EmoryHuang
 * @Date: 2021-12-23 14:42:20
 * @Method:
 * ���� + �ַ�����ϣ
 * ʹ�ö��ֲ�����ظ��Ӵ��ĳ��ȣ�������ϣ�����ظ����ֵ��Ӵ�
 * */
 
class Solution {
   public:
    vector<unsigned long long> h, p;
    string check(string s, int len) {
        int n = s.size();
        unordered_set<unsigned long long> st;
        // ������ϣ�����ظ����ֵ��Ӵ�
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            // ѯ���Ӵ���ϣ
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
        // h[i] ��ʾ f(s[1...i]), ��ԭ������Ϊ i ��ǰ׺�Ĺ�ϣֵ
        // p[i] Ϊ�η�����
        for (int i = 0; i < n; i++) {
            h[i + 1] = h[i] * B + s[i];
            p[i + 1] = p[i] * B;
        }
        string ans;
        int l = 0, r = n;
        while (l < r) {
            // mid Ϊ��ظ��Ӵ��ĳ���
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