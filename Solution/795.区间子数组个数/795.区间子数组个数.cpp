/*
 * @Descroption: LeetCode 795. �������������
 * @Author: EmoryHuang
 * @Date: 2021-08-15 12:27:18
 * @Method:
 * ��̬�滮
 * ʹ��count����������С�ڵ���x�������������
 * ���Ľ����Ϊcount(right) - count(left - 1)
 */

class Solution {
   public:
    int count(vector<int> nums, int x) {
        int ans = 0, cur = 0;
        for (auto num : nums) {
            cur = num <= x ? cur + 1 : 0;
            ans += cur;
        }
        return ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) { 
        return count(nums, right) - count(nums, left - 1); 
    }
};