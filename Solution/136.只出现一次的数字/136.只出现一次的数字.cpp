/*
 * @Descroption: LeetCode 136. ֻ����һ�ε�����
 * @Author: EmoryHuang
 * @Date: 2021-03-20 15:08:36
 * @����˼·:
 * ��������Ӧ��
 * �����ɣ�`a ^ b ^ c <=> a ^ c ^ b`
 * �κ����� 0 ���Ϊ�κ��� `0 ^ n => n`
 * ��ͬ�������Ϊ 0: `n ^ n => 0`
 */

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};