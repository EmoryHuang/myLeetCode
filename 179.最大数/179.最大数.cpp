/*
 * @Descroption: LeetCode 179. 最大数
 * @Author: EmoryHuang
 * @Date: 2021-04-12 19:30:36
 * @解题思路: 重写`sort()`，首位数字大的排在前面，之后依次连接即可
 * 巧妙点在于 `sa + sb > sb + sa`
 */

class Solution {
   public:
    static bool cmp(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        if (nums[0] == 0) return "0";
        for (int i = 0; i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }
        return ans;
    }
};