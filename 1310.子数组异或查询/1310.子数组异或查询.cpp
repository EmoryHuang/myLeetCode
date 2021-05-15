/*
 * @Descroption: LeetCode 1310. 子数组异或查询
 * @Author: EmoryHuang
 * @Date: 2021-05-12 15:41:36
 * @解题思路:
 * `nums[i]` 为从 `arr[0]` 到 `arr[i-1]` 的异或结果
 * 对于查询 `[left,right]`，只需要计算 `nums[left] ^ nums[right + 1]`
 */

class Solution {
   public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
        vector<int> nums(n + 1), ans(m);
        // nums[i] 为从 arr[0] 到 arr[i-1] 的异或结果
        for (int i = 0; i < n; i++) {
            nums[i + 1] = nums[i] ^ arr[i];
        }
        for (int i = 0; i < m; i++) {  // 区间异或
            ans[i] = nums[queries[i][0]] ^ nums[queries[i][1] + 1];
        }
        return ans;
    }
};