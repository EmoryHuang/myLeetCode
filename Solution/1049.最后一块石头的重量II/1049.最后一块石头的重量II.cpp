/*
 * @Descroption: LeetCode 1049. ���һ��ʯͷ������ II
 * @Author: EmoryHuang
 * @Date: 2021-06-08 15:28:00
 * @����˼·:
 * 01��������
 * dp[j]��ʾ����Ϊj�ı��������Էŵ�ʯͷ����
 * ������Գ���Ϊ�� n ��ʯͷ��Ϊ���ѣ�����������ʯͷ�����ܺ͵���С��ֵ
 * ������˵���� stones ������ѡ�񣬴ճ��ܺͲ����� sum/2 ������ֵ��
 */

class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int stone : stones) sum += stone;
        // dp[j]��ʾ����Ϊj�ı��������Էŵ�ʯͷ����
        // ������������Ϊʯͷ��������һ��
        vector<int> dp(sum / 2 + 1);
        for (int stone : stones) {
            for (int j = sum / 2; j >= stone; j--) {
                dp[j] = max(dp[j], dp[j - stone] + stone);
            }
        }
        return sum - dp[sum / 2] * 2;
    }
};