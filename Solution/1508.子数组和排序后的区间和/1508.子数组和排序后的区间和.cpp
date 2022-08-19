/*
 * @Descroption: LeetCode 1508. ������������������
 * @Author: EmoryHuang
 * @Date: 2021-08-11 14:58:42
 * @Method:
 * ��������
 * �õ����е�������ĺ�֮�󣬶���������Ȼ�����ָ�����±귶Χ�ڵ�Ԫ��֮��
 */

class Solution {
   public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                sums.push_back(sum);
            }
        }
        sort(sums.begin(), sums.end());
        int ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sums[i]) % 1000000007;
        }
        return ans;
    }
};