/*
 * @Descroption: 面试题 08.03. 魔术索引
 * @Author: EmoryHuang
 * @Date: 2021-07-28 19:03:44
 * @Method:
 * 简单题，遍历数组
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