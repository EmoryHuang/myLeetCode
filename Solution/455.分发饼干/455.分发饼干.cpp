/*
 * @Descroption: LeetCode 455. �ַ�����
 * @Author: EmoryHuang
 * @Date: 2021-06-08 19:48:00
 * @����˼·:
 * ̰��˼�룬�� s �� g ��������Ȼ���жϵ�ǰ�����Ƿ�������㵱ǰ���ӵ�����
 */

class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0, cookies = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (cookies < s.size() && ans < g.size()) {
            // ��ǰ���ɿ������㵱ǰ���ӵ�����
            if (s[cookies] >= g[ans]) ans++;
            cookies++;
        }
        return ans;
    }
};