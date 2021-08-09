/*
 * @Descroption: ��ָ Offer 57. ��Ϊs����������
 * @Author: EmoryHuang
 * @Date: 2021-08-09 14:31:19
 * @Method:
 * ˫ָ�������Ѱ�Һ�Ϊtarget������
 */

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] == target)
                return {nums[l], nums[r]};
            else if (nums[l] + nums[r] > target)
                r--;
            else
                l++;
        }
        return {};
    }
};