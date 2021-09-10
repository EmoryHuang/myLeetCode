/*
 * @Descroption: LeetCode 1524. 和为奇数的子数组数目
 * @Author: EmoryHuang
 * @Date: 2021-08-09 19:29:25
 * @Method:
 * 前缀和
 * 统计当前前缀和的子前缀和奇数偶数的个数
 * 当下标 i 的位置的前缀和是偶数时，和为奇数的子数组的数量即为奇数前缀和的数量 odd
 * 当下标 i 的位置的前缀和是奇数时，和为奇数的子数组的数量即为偶数前缀和的数量 even
 */

class Solution {
   public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1;
        int ans = 0, sum = 0;
        for (int num : arr) {
            sum += num;
            ans = (ans + (sum % 2 == 0 ? odd : even)) % 1000000007;
            if (sum % 2 == 0)
                even++;
            else
                odd++;
        }
        return ans % 1000000007;
    }
};