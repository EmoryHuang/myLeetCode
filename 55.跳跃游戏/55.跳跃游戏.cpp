/*
 * @Descroption: LeetCode 55. ��Ծ��Ϸ
 * @Author: EmoryHuang
 * @Date: 2021-05-12 15:57:36
 * @����˼·: �������飬ÿһ�������ܹ���������ֵ `reach`���� `i > reach` ��˵�����ܵ���
 */

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > reach) return false;
            reach = max(reach, i + nums[i]);  // ÿ��һ�������ܹ���������ֵ
        }
        return true;
    }
};