/*
 * @Descroption: LeetCode 821. �ַ�����̾���
 * @Author: EmoryHuang
 * @Date: 2021-05-22 14:34:00
 * @����˼·:
 * �������ұ�������¼��һ���ַ� C ���ֵ�λ�� prev����ô�𰸾��� i - prev��
 * ���������������¼��һ���ַ� C ���ֵ�λ�� prev����ô�𰸾��� prev - i��
 * ������ֵȡ��С���Ǵ𰸡�
 */

class Solution {
   public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size());
        int pre = -0x3f3f3f3f;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) pre = i;
            ans[i] = i - pre;
        }
        pre = 0x3f3f3f3f;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == c) pre = i;
            ans[i] = min(ans[i], pre - i);
        }
        return ans;
    }
};