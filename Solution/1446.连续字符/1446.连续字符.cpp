/*
 * @Descroption: LeetCode 1446. �����ַ�
 * @Author: EmoryHuang
 * @Date: 2021-04-19 13:15:36
 * @����˼·:
 * ���⣬����һ���¼������ַ�������
 */

class Solution {
   public:
    int maxPower(string s) {
        int len = s.size();
        if (len == 1) return 1;
        int ans = 0, tmp = 0;
        for (int i = 0; i < len - 1; i++) {
            if (s[i] == s[i + 1])
                tmp++;
            else
                tmp = 0;
            ans = max(ans, tmp + 1);
        }
        return ans;
    }
};