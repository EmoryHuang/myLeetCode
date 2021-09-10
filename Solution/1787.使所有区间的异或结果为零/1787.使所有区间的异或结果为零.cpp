/*
 * @Descroption: LeetCode 1787. ʹ��������������Ϊ��
 * @Author: EmoryHuang
 * @Date: 2021-05-25 11:31:11
 * @����˼·:
 * ���ȣ��������Ȼ��ÿ k ��һ������ظ���
 * ��˿��Խ����һά�����뿴�ɶ�ά��
 * �Ӷ�������ת��Ϊ��ʹ������ÿ����ȣ�ͬʱ�����С������ֵΪ 0 ����С�޸Ĵ�����
 *
 * dp[i][j] ��ʾÿ��������ǰ i �����ֽ�����򣬵õ� j �������С����
 * ʹ�ù�ϣ���¼ÿһ�е����ֱַ�����˶��ٴΣ�ʹ�ñ��� cnt ͳ�Ƹ����ж�������
 * ����ĳһ������������count[i]�Σ���ʱ�൱�ڸı���������
 * dp[i][j]Ӧ��ȡ dp[i-1] �е���Сֵ + count[i]
 *
 * dp[i][j ^ num] = min(dp[i][j ^ num], dp[i - 1][j] + change(num))
 * ˵����
 * ������Ҫ�ı䵱ǰ�е�����num����ôȡ min(dp[i-1][0]~dp[i-1][1024]+cnt[i])��Ҳ��������˵��
 * ����Ҫ�ı䵱ǰ�е�����num����ôȡ dp[i - 1][j] + change(num)��change(num)Ϊ��Ҫ�ı���������
 * ת��ȡ��Сֵ�����վ�Ӧ��Ϊdp[k-1][0]
 */

class Solution {
   public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAX = 1024;
        vector<int> count(k);
        vector<unordered_map<int, int>> hash(k);
        for (int i = 0; i < n; i++) {
            count[i % k]++;          // ������������
            hash[i % k][nums[i]]++;  // ÿһ�е����ֱַ�����˶��ٴ�
        }
        // dp[i][j] ��ʾÿ��������ǰ i �����ֽ�����򣬵õ� j �������С����
        vector<vector<int>> dp(k, vector<int>(MAX));
        for (int j = 0; j < MAX; j++) dp[0][j] = count[0] - hash[0][j];  // ��ʼ��
        for (int i = 1; i < k; i++) {
            int minc = *min_element(dp[i - 1].begin(), dp[i - 1].end());  // ǰһ����Ҫ�ı����Сֵ
            // ����ĳһ������������count[i]�Σ���ʱ�൱�ڸı���������
            // dp[i][j]Ӧ��ȡ dp[i-1] �е���Сֵ + count[i]
            for (int j = 0; j < MAX; j++) dp[i][j] = minc + count[i];
            for (auto p : hash[i % k]) {  // ����ÿһ�е�ֵ
                for (int j = 0; j < MAX; j++) {
                    int num = p.first, c = p.second;
                    dp[i][j ^ num] = min(dp[i][j ^ num], dp[i - 1][j] + count[i] - c);
                }
            }
        }
        return dp[k - 1][0];
    }
};