/*
 * @Descroption: LeetCode 1296. 划分数组为连续数字的集合
 * @Author: EmoryHuang
 * @Date: 2021-07-15 19:52:22
 * @解题思路:
 * 用哈希表记录各个元素的数量
 * 对排序后的元素进行遍历，对于每个元素 num
 * 若 num + i 的个数为0，则返回 false
 */

class Solution {
   public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        for (auto num : nums) mp[num]++;
        for (auto num : nums) {
            if (mp[num] == 0) continue;
            for (int i = 0; i < k; i++) {
                if (mp.count(num + i) == 0) return false;
                mp[num + i]--;
            }
        }
        return true;
    }
};