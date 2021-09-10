/*
 * @Descroption: ��ָ Offer II 008. �ʹ��ڵ��� target �����������
 * @Author: EmoryHuang
 * @Date: 2021-08-07 14:42:17
 * @Method:
 * ��������
 * ��������еĺʹ��� target������˵������ƶ�����������С����
 */

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        int ans = INT_MAX, sum = 0;
        while (r < n) {
            sum += nums[r++];
            while (sum >= target) {
                ans = min(ans, r - l);
                sum -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};