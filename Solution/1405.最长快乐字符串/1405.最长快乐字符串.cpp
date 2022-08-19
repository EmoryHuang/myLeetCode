/*
 * @Descroption: LeetCode 1405. ������ַ���
 * @Author: EmoryHuang
 * @Date: 2022-02-07 10:37:28
 * @Method:
 * ����ʣ��������������
 * ̰�Ĳ��ԣ�ÿ�ξ���������ʹ�õ�ǰ����������ĸ
 * ʹ������������ĸ: ����ַ�������С�� 2; ��������ַ����䲻��ͬ; ����������ĸ����
 * ����ʹ�������ڶ������ĸ
 */


class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        vector<pair<int, char>> cnt = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (true) {
            int n = ans.size();
            // ����ʣ��������������
            sort(cnt.begin(), cnt.end(), [](const pair<int, char>& a, const pair<int, char>& b) { return a.first > b.first; });
            if (cnt[0].first && (n < 2 || !(ans[n - 1] == cnt[0].second && ans[n - 2] == cnt[0].second))) {
                //ʹ������������ĸ
                // ����������ĸ���� and (����ַ�������С�� 2 or ��������ַ����䲻��ͬ)
                ans += cnt[0].second;
                cnt[0].first--;
            } else if (cnt[1].first) {
                // ʹ�������ڶ������ĸ
                ans += cnt[1].second;
                cnt[1].first--;
            } else {
                break;
            }
        }
        return ans;
    }
};