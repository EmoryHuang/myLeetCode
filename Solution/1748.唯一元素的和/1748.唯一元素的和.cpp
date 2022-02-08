/*
 * @Descroption: LeetCode 1748. 唯一元素的和
 * @Author: EmoryHuang
 * @Date: 2022-02-06 10:57:49
 * @Method:
 * 简单题，由于数据量较少，可以直接用hash记录元素出现的次数
 */

class Solution {
   public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> cnt(101, 0);
        for (auto num : nums) cnt[num]++;
        int ans = 0;
        for (int i = 0; i < 101; i++)
            if (cnt[i] == 1) ans += i;
        return ans;
    }
};