/*
 * @Descroption: LeetCode 1884. ��������-��ö����
 * @Author: EmoryHuang
 * @Date: 2021-07-20 19:42:58
 * @����˼·:
 * ��̬�滮
 * dp[i]��ʾ¥�� i ����һö����û��ʱ����С��������
 * �����һö������ j �����ˣ���ô��ʣһö��������ʱȷ�� f ����Ҫ�ӵ� 1 ����������ӵ� j ��
 * �����һö������ j ��û�飬��ô��Ҫ���� i-j ������ö����ʱ�Ĳ����������ټ��ϵ�ǰ��β���
 */

class Solution {
   public:
    int twoEggDrop(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++) dp[i] = min(dp[i], max(j, dp[i - j] + 1));
        return dp[n];
    }
};