/*
 * @Descroption: LeetCode 1848. ��Ŀ��Ԫ�ص���С����
 * @Author: EmoryHuang
 * @Date: 2021-06-16 15:29:00
 * @����˼·:
 * ���⣬����һ�����飬�ҵ� target ��Ȼ��Ѱ����С����
 */

class Solution {
   public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target) ans = min(ans, abs(i - start));
        return ans;
    }
};