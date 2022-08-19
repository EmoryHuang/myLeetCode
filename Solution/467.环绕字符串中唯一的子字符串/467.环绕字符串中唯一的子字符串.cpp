/*
 * @Descroption: LeetCode 467. �����ַ�����Ψһ�����ַ���
 * @Author: EmoryHuang
 * @Date: 2022-05-25 09:15:42
 * @Method:
 * ��̬�滮
 * dp[i] ��ʾ�� i ��β���Ӵ��������
 * ������ص���ֻ��Ҫ�������һ������Ϊ�����������п��ܵ����ַ���
 * ������˵������ p����ά�������������Ӵ�����
 * �����ǰ�ַ�����һ���ַ��� s ����������ô�Ե�ǰ�ַ���β������Ⱦʹ�ǰ���ۼӣ���������µĿ�ʼ��
 */


class Solution {
   public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        if (n < 1) return 0;
        // dp[i] ��ʾ�� i ��β���Ӵ��������
        // ������ص���ֻ��Ҫ�������һ������Ϊ�����������п��ܵ����ַ���
        vector<int> dp(26);
        // ά�������������Ӵ�����
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            // �ж��Ƿ���ѭ���Ӵ���
            if (i > 0 && (p[i] - p[i - 1] + 26) % 26 == 1)
                max_len++;
            else
                max_len = 1;
            dp[p[i] - 'a'] = max(max_len, dp[p[i] - 'a']);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) ans += dp[i];
        return ans;
    }
};