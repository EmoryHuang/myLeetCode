/*
 * @Descroption: LeetCode 2006. 差的绝对值为 K 的数对数目
 * @Author: EmoryHuang
 * @Date: 2021-10-08 19:22:02
 * @Method:
 * 哈希表记录之前的数据个数
 */

class Solution {
   public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> hash(101);
        int ans = 0;
        for (int num : nums) {
            if (num - k >= 0) ans += hash[num - k];
            if (num + k <= 100) ans += hash[num + k];
            hash[num]++;
        }
        return ans;
    }
};