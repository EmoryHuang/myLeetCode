/*
 * @Descroption: LeetCode 1200. 最小绝对差
 * @Author: EmoryHuang
 * @Date: 2021-05-26 16:02:17
 * @解题思路:
 * 对数组进行排序，寻找相邻的差值最小的两个元素
 * 若差值小于diff，则更新diff，并清空ans
 * 若差值等于diff，则加入ans
 */

class Solution {
   public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] < diff) {  // 如果当前两个数的差更小
                ans.clear();
                ans.push_back({arr[i - 1], arr[i]});
                diff = arr[i] - arr[i - 1];
            } else if (arr[i] - arr[i - 1] == diff)
                ans.push_back({arr[i - 1], arr[i]});
        }
        return ans;
    }
};