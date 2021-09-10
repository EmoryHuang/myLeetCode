/*
 * @Descroption: LeetCode 611. 有效三角形的个数
 * @Author: EmoryHuang
 * @Date: 2021-04-28 14:33:36
 * @解题思路:
 * 从大到小遍历最长边，然后设置双指针寻找合适的`j`，`k`，`[j, k - 1]`都符合条件
 */

class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = nums.size() - 1; i >= 2; i--) {  // 枚举最长边
            int j = 0;
            int k = i - 1;
            while (j < k) {  //双指针
                if (nums[i] < nums[j] + nums[k]) {
                    cnt += k - j;  // [j, k - 1]都符合条件
                    k--;
                } else
                    j++;
            }
        }
        return cnt;
    }
};