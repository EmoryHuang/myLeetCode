/*
 * @Descroption: ������ 08.03. ħ������
 * @Author: EmoryHuang
 * @Date: 2021-07-28 19:03:44
 * @Method:
 * ���⣬��������
 */

class Solution {
   public:
    int findMagicIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums[i]) return i;
        }
        return -1;
    }
};