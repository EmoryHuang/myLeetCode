/*
 * @Descroption: LeetCode 403. ���ܹ���
 * @Author: EmoryHuang
 * @Date: 2021-04-29 16:32:36
 * @����˼·:
 * ���ڵ�`i`��ʯͷ��ǰ���ʯͷ`j`�ܷ�������ʯͷ,������ʯͷ��ľ���Ϊ`diff = stones[i]-stones[j]`
 * ��Ҫ�ж� `j` �Ƿ���ڿ�����Ծ `diff` �� ��������������������� ʯͷ `j` ǰ���ʯͷ������
 * ��ǰ���ܹ��� `diff` ��ʯͷ `i` ʱ����ôʯͷ `i` �����Ĳ������� `diff - 1 || diff || diff + 1`
 * ��ˣ�`dp[i][j]` ��ʾ �� `i` ��ʯͷ�Ƿ������ `j` ��
 */

class Solution {
   public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<vector<bool>> dp(len, vector<bool>(len + 1));
        dp[0][1] = true;  // ��0��ʯͷ������1��
        for (int i = 1; i < len; i++) {
            bool flag = false;
            for (int j = i - 1; j >= 0; j--) {  // �Ӻ���ǰö��
                int diff = stones[i] - stones[j];
                if (diff > i) break;        // �������޷��ﵽ
                if (dp[j][diff] == true) {  // �����j��ʯͷ����diff��
                    // ��ô˵����j��ʯͷ������i�����i��ʯͷ����Ĳ���
                    dp[i][diff - 1] = true;
                    dp[i][diff] = true;
                    dp[i][diff + 1] = true;
                    flag = true;
                }
            }
            // �������յ�
            if (i == len - 1 && !flag) return false;
        }
        return true;
    }
};