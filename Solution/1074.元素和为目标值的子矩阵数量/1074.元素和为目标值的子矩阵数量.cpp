/*
 * @Descroption: LeetCode 1074. Ԫ�غ�ΪĿ��ֵ���Ӿ�������
 * @Author: EmoryHuang
 * @Date: 2021-05-29 13:21:56
 * @����˼·:
 * ������Ҫ�����άǰ׺��
 * ���������Ӿ�����Ҫö�١��������Ͻǡ��͡��������½ǡ�����ʱ��
 *
 * ͨ����ϣ���Ż�
 * ö���ϣ��£��ұ�
 * �ѡ��Ӿ����ұ߽硹����ԭ������߽硹�ľ���� cur �����ϣ��
 * ����ϣ���ҵ������Ϊ target ���Ӿ���
 * ��ȼ��ڴӡ���ϣ�����ҵ�һ�� x��ʹ�� cur - x = target
 */

class Solution {
   public:
    // ���ض�άǰ׺�ͣ���ʱ��
    // int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<vector<int>> arr(m + 1, vector<int>(n + 1));
    //     for (int i = 1; i <= m; i++)
    //         for (int j = 1; j <= n; j++)
    //             arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + matrix[i - 1][j - 1];
    //     int ans = 0;
    //     for (int i = 1; i <= m; i++) {
    //         for (int j = 1; j <= n; j++) {
    //             for (int p = 1; p <= i; p++) {
    //                 for (int q = 1; q <= j; q++) {
    //                     int sum = arr[i][j] - arr[i][q - 1] - arr[p - 1][j] + arr[p - 1][q - 1];
    //                     if (sum == target) ans++;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // �Ż�
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> arr(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + matrix[i - 1][j - 1];
        int ans = 0;
        for (int top = 1; top <= m; top++) {        // �����ϱ߽�
            for (int bot = top; bot <= m; bot++) {  // �����±߽�
                int cur = 0;                        // ���
                map<int, int> mp;                   // map��Ϊ{���������}
                for (int r = 1; r <= n; r++) {      // �����ұ߽�
                    // �����߽�������Ե��Χ�ɾ��ε����
                    cur = arr[bot][r] - arr[top - 1][r];
                    if (cur == target) ans++;
                    // �������Ϊ cur - target �ľ���
                    if (mp.count(cur - target)) ans += mp[cur - target];
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};