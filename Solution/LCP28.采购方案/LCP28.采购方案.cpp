/*
 * @Descroption: LCP 28. �ɹ�����
 * @Author: EmoryHuang
 * @Date: 2021-07-08 19:46:06
 * @����˼·:
 * ���⣬���� + ˫ָ��
 */

class Solution {
   public:
    int purchasePlans(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = 0;
        sort(nums.begin(), nums.end());
        while (l < r) {
            if (nums[l] + nums[r] > target)
                r--;
            else {
                ans += r - l;
                ans %= 1000000007;
                l++;
            }
        }
        return ans;
    }
};