/*
 * @Descroption: LeetCode 395. ������ K ���ظ��ַ�����Ӵ�
 * @Author: EmoryHuang
 * @Date: 2021-10-13 20:17:15
 * @Method:
 * ˫ָ��
 * ����ֻ�����Сд��ĸ�����Ա���������ĸ������
 * ��¼�ж����ַ�����Ҫ�󣬵������������ַ�������ʱ���´�
 */

class Solution {
   public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        // ����������ĸ������
        for (int p = 1; p <= 26; ++p) {
            vector<int> hash(26);
            int l = 0, r = 0;
            // cnt ��ʾ���ֵ���ĸ������total ��ʾ������������ĸ����
            int cnt = 0, total = 0;
            for (int r = 0; r < s.size(); r++) {
                int u = s[r] - 'a';
                hash[u]++;
                if (hash[u] == 1) cnt++;    // ����������ĸ
                if (hash[u] == k) total++;  // ������������������ĸ
                // ������ĸ���������� p
                while (cnt > p) {
                    int v = s[l++] - 'a';
                    hash[v]--;
                    if (hash[v] == 0) cnt--;
                    if (hash[v] == k - 1) total--;
                }
                if (cnt == total) ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};