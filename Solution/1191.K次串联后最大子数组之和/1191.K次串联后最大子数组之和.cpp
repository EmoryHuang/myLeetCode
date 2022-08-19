/*
 * @Descroption: LeetCode 1191. K �δ��������������֮��
 * @Author: EmoryHuang
 * @Date: 2021-10-15 11:18:50
 * @Method:
 * ��̬�滮
 * �� k == 1, ��ô���ǵ��������������֮��
 * �� k == 2, ͬ������ k == 1 ����, ���ǵ�һ���ֵĺ�׺ + �ڶ����ֵ�ǰ׺
 * �� k > 2, ѭ���м䲿���ܺ�
 */

class Solution {
   public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int ans = 0, cur = 0, n = arr.size();
        int sum = 0;
        for (int num : arr) sum += num;
        for (int i = 0; i < min(2, k) * n; i++) {
            cur = max(cur + arr[i % n], arr[i % n]);
            ans = max(ans, cur);
        }
        while (sum > 0 && k-- > 2) ans = (ans + sum) % 1000000007;
        return ans % 1000000007;
    }
};