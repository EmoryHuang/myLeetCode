/*
 * @Descroption: LeetCode 1387. ��������Ȩ������
 * @Author: EmoryHuang
 * @Date: 2021-08-27 15:23:58
 * @Method:
 * ֱ�� insert
 */

class Solution {
   public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) ans.insert(ans.begin() + index[i], nums[i]);
        return ans;
    }
};