/*
 * @Descroption: LeetCode 1748. 唯一元素的和
 * @Author: EmoryHuang
 * @Date: 2021-05-06 18:48:36
 * @解题思路:
 * 使用 map 统计元素出现的次数，遍历数组，统计唯一元素的和
 */

class Solution {
   public:
    int sumOfUnique(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;
        for (int num : nums) {
            if (mp[num] == 0)
                ans += num;
            else if (mp[num] == 1)
                ans -= num;
            mp[num]++;
        }
        return ans;
    }
};