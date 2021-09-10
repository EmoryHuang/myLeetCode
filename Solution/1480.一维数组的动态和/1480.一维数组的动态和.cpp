/*
 * @Descroption: LeetCode 1480. һά����Ķ�̬��
 * @Author: EmoryHuang
 * @Date: 2021-05-07 19:50:36
 * @����˼·:
 * ���⣬�������飬��ÿ�ε��ۼӷ�������
 */

class Solution {
   public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            ans.push_back(sum);
        }
        return ans;
    }
};