/*
 * @Descroption: LeetCode 488. ������Ϸ
 * @Author: EmoryHuang
 * @Date: 2021-11-09 15:52:52
 * @Method:
 * dfs + ��֦
 * ���ѣ������������Լ����Բ����ÿ��λ�ã�����С�Ĳ������
 * ʹ��һ�� int ����¼ hand ��ʹ�����
 */

class Solution {
    int INF = 0x3f3f3f3f;
    string b;
    int m;
    unordered_map<string, int> map;

    int dfs(string &a, int cur) {
        if (a.length() == 0) return 0;
        if (map.count(a)) return map[a];
        int ans = INF;
        int n = a.length();
        //����������
        for (int i = 0; i < m; ++i) {
            //�����ǰ���Ѿ���ȡ��������������
            if (((cur >> i) & 1) == 1) continue;
            //����ǰȡ���������
            int next = (1 << i) | cur;
            //����������λ��
            for (int j = 0; j <= n; ++j) {
                string s = "";
                s += a.substr(0, j) + b[i];
                if (j != n) s += a.substr(j);
                int k = j;
                while (0 <= k && k < s.length()) {
                    char c = s[k];
                    int l = k, r = k;
                    //������ɢ�����������ڵ��������ַ�,Ȼ��ɾ��
                    while (l >= 0 && s[l] == c) l--;
                    while (r < s.length() && s[r] == c) r++;
                    if (r - l - 1 >= 3) {
                        s.erase(l + 1, r - l - 1);
                        k = l >= 0 ? l : r;
                    } else {
                        break;
                    }
                }
                ans = min(ans, dfs(s, next) + 1);
            }
        }
        map[a] = ans;
        return ans;
    }

   public:
    int findMinStep(string board, string hand) {
        b = hand;
        m = hand.length();
        int ans = dfs(board, 1 << m);
        return ans == INF ? -1 : ans;
    }
};