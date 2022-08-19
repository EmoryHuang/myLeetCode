/*
 * @Descroption: ��ָ Offer II 009. �˻�С�� K ��������
 * @Author: EmoryHuang
 * @Date: 2021-08-10 20:19:11
 * @Method:
 * ��������
 * �������飬����ǰ�˻�δ���� k������봰�ڣ������ƶ��󴰿�
 */

class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0 || k == 1) return 0;
        int l = 0;
        int ans = 0, mul = 1;
        for (int r = 0; r < nums.size(); r++) {
            mul *= nums[r];
            while (mul >= k) mul /= nums[l++];
            ans += r - l + 1;
        }
        return ans;
    }
};